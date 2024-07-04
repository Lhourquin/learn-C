#include <stdio.h>
#include "increment.h"
int increment(){
	static int number_to_increment = 0;
	number_to_increment++;
	display_something("Something");
	return number_to_increment;
}

static void display_something(char string[10]){
	puts(string);
}
