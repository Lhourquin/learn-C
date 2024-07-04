#include <stdio.h>

int increment(){
	static int number_to_increment = 0;
	number_to_increment++;
	return number_to_increment;
}
