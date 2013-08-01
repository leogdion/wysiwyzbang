//int hello_world ();


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

typedef struct _wwb_configuration_builder
{
} wwb_configuration_builder;

typedef struct _wwb_configuration {
} wwb_configuration;


wwb_configuration_builder * wwb_configuration_builder_create ();
wwb_configuration * wwb_configuration_create (wwb_configuration_builder * builder);
int wwb_main (wwb_configuration * wwb_configuration);