#include <stdio.h>
#include <stdlib.h>

int main(void){
/*
	when we declare a variable, we have to allocate a memory to store them.
*/
	int my_number = 0;//automatic allocation of memory, that will be freeing at the end of the function automaticaly also
/*
	when we declare variable, the program request to the OS (linux, macos, windows etc) the permission to use a litle memory.
	the operating system tells to programs where it can store the value of this variable (it give the reserved address to sotre them)
	when the function is finish, the variable is remove from the memory, and the  program tell to the operating system : I not longer need this space of ememory you reserved to me at this address.
*/

//Request memory with malloc (dynamic/manually allocation)
	int *age = NULL;
	age = malloc(sizeof(int));
	if(age == NULL){
		exit(0);
	}
	printf("How old are you ?");
	scanf("%d", age);
	printf("You have %d years old\n", *age);
	return 0;
}
