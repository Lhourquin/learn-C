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
int global_number;//to get access of the variable global from air.c, i declare here the variable, the variable from air. give to this the value 57
int static_number;
int main(int argc,const char *argv[]){
	double result;
	result = air_rectangle(5, 10);
	printf(" \nWINKY\n");
	printf("Rectangle de largeur 5 et de haueur 10. Aire = %f\n", result);
printf("%d print global_number from main.c\n", global_number);//57 like in the air.c because is global for all file
	printf("print the static_number form main.c %d\n", static_number);//0 because is declared here like a variable global for this file, the value of 58 stay in air.c because it static.
	return 0;
}

