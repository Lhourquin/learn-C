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
/*
	malloc prototype:
	void* malloc(size_t number_of_necesary_bytes);
	these function retrun a pointer empty of any type, and thses parametter is the size we need, we can use sizeof function with the type in parametters to specify the number of bytes we want to use, in this case is type of int, so it will take 4 bytes in memory
*/


	if(age == NULL){
		exit(0);//if is NULL, stop immediatly the program
	}
	printf("How old are you ?");
	scanf("%d", age);
	printf("You have %d years old\n", *age);
/*
	freeing memory:
	like fclose, the free function will freeing memeory after we finish to use and we no longer need to use this.
	their prototype:
	void free(void* pointer);
	it take in parametter the pointer we have used with malloc earlier.		
	
*/
	free(age);// we no longer need memory, we freeing it manally like this.
/*
	age in a pointer, we don't use it at the same way with a real variable.
		* to get the value of the variable, we put before them the symbol * like we see earlier in the course about pointer
		* to specify these address, we just puts the name of the pointer in the function, without the symbol &
	
*/
//	what we doing is like doing this ⬇️ ****
	int another_age = 0;//allocate memory to the variable of type int, will take 4 bytes.
	//using of the memory
	printf("How old are you ?");
	scanf("%d", &another_age);
	printf("You have %d years old\n", another_age);
	
	
	return 0;
}//**** freeing memory no longer need automatically

/*
	Conclusion:
	we have two way to allocate memory:
		* manualy by using malloc() and free() function
		* automatically by declaration of a variable
*/
