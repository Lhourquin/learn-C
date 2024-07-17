#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
/*
	In C, when we make a complex project, we can create our type of variable.
		* structure
		* enumeration
	
*/
int main(void){
//structure
/*
	What is a struture ?
	
	A structure is a set of variable could have different types.
	Unlike an array, is not obligatory to have all data of a same type,
	you can create a structure including variable of type, char, int and double at the same time.
	struct is generaly define in .h file, like prototype and defines directives.
	
*/	
	//to define a struture we use the keyword struct before the name of the structure
	struct My_structure_example{
		int number;
		int number_2;

		double decimal_number;

		char letter;
	};//a good practice consist of follow the same rules for syntax declaration of variable, but we Uppercase the first letter.
	//it useful for example if we work in 2D with two axis
/*
	struct Coordinate{
		int x;//Abscisses
		int y;//Ordonates
	};
*/
	struct Coordinates point;//create variable point of type Coordinates. Always use struct keywoard to specify at the computer is a custom type, like Coordinates. But is a litlle bit painful to do that, so devevelopper invented 'typedef', it is what we used for Another_coordinates.
	point.x = 32;
	point.y = 20;	
	printf("point x: %d\n", point.x);
	printf("point y: %d\n", point.y);

	Another_coordinates another_point;//as declared the struture with an alias strutcture in struct.h with a typedef instruction, so we don't need to use keyword struct before here/
	another_point.x = 100;
	another_point.y = 300;
	printf("another_point x: %d\n", another_point.x);
	printf("another_point y: %d\n", another_point.y);
	
	//struct can contains array
	struct Person{
		char first_name[100];
		char last_name[100];
		char address[100];
		
		int student;//Boolean: 1 = student, 0 = not student.
		int age;
	};
/*	
	This struture is composed by 5 sub variables. 
		* The first three have char type to store fist_name, last_name, and address.
		* The last two have int type to store age and Boolean to check if is sutdent or not.
	Not limit of variable if we want to add variable in structure to complete him.
*/	
	//use struct in function
	
	
	return 0;
}
