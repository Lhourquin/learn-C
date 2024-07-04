#include "air.h"
#include <stdio.h>

//scope of variable
/*
	if I declare a global variable(that mean outside a function) this variable must be accessible in all file 
*/
int global_number = 57;
static int static_number = 58;//this variable is global for the file but we cannot access to it from another file because we use the static keywoard, this specifies to the compiler that the variable is only accessible in this file
double air_rectangle(double largeur, double hauteur){
	printf("print global_number from air.c %d\n",global_number);
	printf("print static number from air.c %d\n",static_number);//58 because is  declared here
	puts("tinky");
	return largeur * hauteur;
}

