#include <stdio.h>
#include "../headers/air.h"
#include "../headers/increment.h"
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
	//call prototype from header file air.h
	double result;
	result = air_rectangle(5, 10);
	printf(" \nWINKY\n");
	
	//global variable
	printf("Rectangle de largeur 5 et de haueur 10. Aire = %f\n", result);
printf("%d print global_number from main.c\n", global_number);//57 like in the air.c because is global for all file
	printf("print the static_number form main.c %d\n", static_number);//0 because is declared here like a variable global for this file, the value of 58 stay in air.c because it static.

	//test the functionnality of keyword static for local variable (inside function)
	printf("increment number, because I use static keyword in function, the local variable it doesn't destory %d\n", increment());//first call the variable is createed and initialized
	//When the function is called a second time, the variable declaration line is simply "skipped". We do not recreate the variable, we reuse the variable that we had already created. As the variable was worth 4, it will now be worth 5, then 6, then 7, etc.
	printf("increment number, because I use static keyword in function, the local variable it doesn't destory %d\n", increment());
	printf("increment number, because I use static keyword in function, the local variable it doesn't destory %d\n", increment());
	printf("increment number, because I use static keyword in function, the local variable it doesn't destory %d\n", increment());
	printf("increment number, because I use static keyword in function, the local variable it doesn't destory %d\n", increment());
	printf("increment number, because I use static keyword in function, the local variable it doesn't destory %d\n", increment());
	printf("increment number, because I use static keyword in function, the local variable it doesn't destory %d\n", increment());
	printf("increment number, because I use static keyword in function, the local variable it doesn't destory %d\n", increment());
	printf("increment number, because I use static keyword in function, the local variable it doesn't destory %d\n", increment());
	printf("increment number, because I use static keyword in function, the local variable it doesn't destory %d\n", increment());
	printf("increment number, because I use static keyword in function, the local variable it doesn't destory %d\n", increment());
	printf("increment number, because I use static keyword in function, the local variable it doesn't destory %d\n", increment());

	//try to use display_something outside increment.c
//	display_something("Stranger Thing");
	//that give us an error because the static declaration means the function is avalaible only for the file where is declared, to use this function outside increment.h, we need to remove static keyword.

	return 0;
}

