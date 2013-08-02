#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#ifdef WIN32   
#include <curses.h>
#else
#include <ncurses.h>
#endif
#include "wwb.h"

static bool keep_running = true;

wwb_configuration * wwb_configuration_create (wwb_configuration_builder * builder) {
    return (wwb_configuration*)malloc(sizeof(wwb_configuration));
}

wwb_configuration_builder * wwb_configuration_builder_create () {
    return (wwb_configuration_builder*)malloc(sizeof(wwb_configuration_builder));
}

void intHandler(int dummy) {
    keep_running = false;
}

/*
wwb_key get_key () {
    wwb_key key;
    special_key sp = NONE;
    int ch;
    ch = getch();           
    if (ch == 0x1B) {
        ch = getch();
        if (ch == 0x5B) {
            ch = getch();
            switch (ch) {
                case 0x41: sp = UP_ARROW; break;
                case 0x42: sp = DOWN_ARROW; break;
                case 0x43: sp = RIGHT_ARROW; break;
                case 0x44: sp = LEFT_ARROW; break;
            }
        }
        key = (wwb_key){sp, -1};
    } else {
        key = (wwb_key){sp, ch};
    }
    return key;
}
*/

char * str_of_chstr (chtype * chstr) {
    int index;
    char * str = (char*) malloc(255 * sizeof(char));
    for (index = 0; index < 255 && chstr[index] != 0; index++) {
        str[index] = (char)(chstr[index]);
    }
    return str;
}

int wwb_main (wwb_configuration * wwb_configuration) {
    int ch;
    chtype chstr [255];
    char * str;
    signal(SIGINT, intHandler);
    int width, height;
    int x, y;
    initscr();          /* Start curses mode          */
    getmaxyx(stdscr, height, width);
    //keypad(stdscr, true);
    char * line = (char*)malloc(width * sizeof(char));
    memset(line, '*', width);
    //printw(line); /* Print Hello World          */
    printw("\n");
    printw("\n");
    printw("\n");
    printw(line);
    noecho();
    move(1, 5);
    refresh();          /* Print it on to the real screen */
    while (keep_running) {

        ch = getch();
        addch(ch);
        //addch('\n');

        getyx(stdscr, y, x);
        mvinchnstr(1,5,chstr,255);
        str = str_of_chstr(chstr);
        mvprintw(6,5,str);
        mvaddchstr(5,5,chstr);
        //printw(str);
        move(1,x);
        
    }
    
    endwin();           /* End curses mode        */

    return 0;
}