#include <stdlib.h>
//int hello_world ();

/*
typedef enum {
	NONE,
	UP_ARROW,
	DOWN_ARROW,
	RIGHT_ARROW,
	LEFT_ARROW
} special_key;

typedef struct _wwb_key
{
	special_key special;
	int value;
} wwb_key;
*/

typedef struct _wwb_result {
	char * label;
	void * id;
} wwb_result;

typedef struct _wwb_result_set {
	wwb_result * results;
	size_t count; 
} wwb_result_set;


typedef struct _wwb_configuration_builder
{
} wwb_configuration_builder;

typedef wwb_result_set * (*wwb_query) (void * id, char * search);

typedef struct _wwb_configuration {
	wwb_query query;
} wwb_configuration;


wwb_configuration_builder * wwb_configuration_builder_create ();
wwb_configuration * wwb_configuration_create (wwb_configuration_builder * builder);
int wwb_main (wwb_configuration * wwb_configuration);