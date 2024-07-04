#include <stdio.h>
#include "../headers/air.h"
/*
	How compilation work ?
		
	when we compile the code, at first we have the preprocessing, all directive we used like #include #define #ifndef etc are called the code and prototype to put the code on the file where it called.
	Then the compilation, each file are compiled to be a object file with .o extension.
	after that, the Linking, all file with the .o extension are linked to be compilation into one execution file.
	so if we want to compile all source file like air.c and main.c, we need to specify them on the command ;
	gcc main.c air.c -o main
	the commend above say "compile main.c and air.c and make exec file called main to execute all the code"
*/
int main(int argc,const char *argv[]){
	double result;
	result = air_rectangle(5, 10);
	printf(" \nWINKY\n");
	printf("Rectangle de largeur 5 et de haueur 10. Aire = %f\n", result);
	return 0;
}

