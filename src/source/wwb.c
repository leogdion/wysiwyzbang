#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef WIN32   
#include <curses.h>
#else
#include <ncurses.h>
#endif
#include "wwb.h"

int hello_world () {
    int width, height;
	initscr();			/* Start curses mode 		  */
    getmaxyx(stdscr, height, width);
    char * line = (char*)malloc(width * sizeof(char));
    memset(line, '*', width);
	//printw(line);	/* Print Hello World		  */
    printw("\n");
    printw("\n");
    printw("\n");
    printw(line);
    move(1, 5);
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return 0;
}