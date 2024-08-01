#include <stdio.h>
#include <stdlib.h>

/*
	pre-request: heap, stack
*/
typedef struct Node{
	int value;
	struct Node *next;
} Node;

void create_array(void);

void ft_swap(int *a, int *b);


int main(void){
	Node *head = NULL;
	head->next = NULL;
	head = malloc(sizeof(Node));
	
}

void create_array(void){
//	int *array = malloc(sizeof(int));//allocate memory on heap, with pointer we can use it in all program. Until is not freeing, we can use it in another program, they don't destroy after the call of the function.
}

void ft_swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
