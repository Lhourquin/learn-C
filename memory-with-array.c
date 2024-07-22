#include <stdio.h>
#include <stdlib.h>
#include "memory-with-array.h"
/*
	create an array who the size will be know at execution:

	usualy we don't use the manualy allocation of memory with simple variable,
	to do so we use the automatic way.
	the main benefits of use it is for array when we don't know in advance the size of it.
*/
int main(void){
// imagine we have a program who store ages of all friends of user in array, we can create an array of int like below ⬇️
//	int friends[15];◀️
/*
	but, what they assure us they have 15 or more or less firends ?
	when we wrinting code, we don't know the size to give at the array in this case,
	the program will know that only at the execution, when the program will ask this.
	
	The benefits of manually allocation is here, in this case.
	we will ask to the user the number of friends he have, 
	then we can allocate dynamicaly the size of the array,
	with only the necessary espace of memory needed,
	neither to small nor to big.
	if the user have 15 friends, the size will be 15 int, if is 28, the size will be 28 int, etc.	
*/
	printf("Friends_informations struct size: %lu\n", sizeof(Friends_informations));//output 104, because int take 4 bytes, and char 1 bytes, and we specify the lenght of array is 100, so the total is 104 bytes.
	int number_of_friends = 0, i = 0;
//	int friends[number_of_friends];//❌ as we se earlier, we cannot use constant or variable in array (before C99), bet we can do this with preprocessor constant (#define MAX_SIZE 50 for instance)
	printf("How many friends do you have ?\n");
	scanf("%d", &number_of_friends);
	
	if(number_of_friends > 0){
		Friends_informations *friends = malloc(number_of_friends * sizeof(Friends_informations));//allocate memory
		if(friends == NULL){
			exit(0);
		}
		
		printf("Friends_informations friends size: %lu\n", sizeof(friends));//output 8, because is the size of pointery
		for(i = 0; i < number_of_friends; i++){
			printf("What is the name of your friend ?\n");
			scanf("%s", friends[i].name);
			printf("What is the age of your friend ?\n");
			scanf("%d", &friends[i].age);
		}
		
		for(i = 0; i< number_of_friends; i ++){
			printf("%s have %d years old\n", friends[i].name, friends[i].age);
		}
		printf("number_of_friends: %d\n", number_of_friends);
		printf("Friends_informations struct size: %lu\n", sizeof(Friends_informations));//output 104
		size_t total_size = number_of_friends * sizeof(Friends_informations);
		printf("Size taking to store friend: %zu\n", total_size);
		free(friends);//freeing memory
	}

	
	return 0;
}

/*
	Conclusion:
	
		* a Variable take more or less space in memory depending on this type	
		* we can know this number of bytes will take with sizeof() function
		* dynamic allocation consist of reserved manually a place in memory for a variable or a an array
		* the allocation of memory is made by malloc() and we did never forget to freeing them with free() as soon we no longer need it
		* the dynamic allocation allows to create an array who the size is determined by a variable at the execution.
*/
