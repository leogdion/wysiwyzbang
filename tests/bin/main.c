#include "wwb.h"

int main () {
	wwb_configuration_builder * builder;
	wwb_configuration * configuration;

	builder = wwb_configuration_builder_create();
	configuration = wwb_configuration_create(builder);
	return wwb_main(configuration);
}