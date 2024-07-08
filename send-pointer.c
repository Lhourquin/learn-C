#include <stdio.h>
#include <stdlib.h>

void triple_pointer(int *pointer);//specify the type in prototype (we receive  a pointer)

int main(void){
	int number = 5;
	printf("%p",&number);
	triple_pointer(&number);//use the & symbol to pass the address, and in the prototype, we have specify in argument we await for a pointer, the pointer is a variable stored a dress of another variable, so it the reason we can use the variable with the ampersound to specify the address.
	int *pointer_number = &number;//use the * to specify is a pointer, and add the address of number with & at pre fix.
	printf("%d\n", number);
	printf("%d\n", *pointer_number);//to display the value of address targeted, use the *
	triple_pointer(pointer_number);
	printf("%d\n", *pointer_number);
	printf("%d\n", number);
	return 0;
}

void triple_pointer(int *pointerOnNumber){
	*pointerOnNumber *= 3;
}
