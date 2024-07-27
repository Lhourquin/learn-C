#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"
/*
	the problem with array: there are immutable,	
	we cannot enlarge or chnage the size after this creation,
	to do that we do creating another.
	
	C language not offer another way to store data,
	by is possible to create our custom system to do this.
	This is why we will see in this course.
*/
/*
	Linked List:
	
	The Linked List is a way to organize a set of data in memory,
	That consist to gather structures by linked it between them by using pointer.
	A Linked List is an assembly of structure linked by pointer.
	Each element can contains what we want: one or many int, double, etc ..
	And of top of that, each element have a pointer to the next element.
	That form a list of pointer, that why is named Linked List
*/
/*
	Contrary of array, the elements of a linked list are not placed side by side in memory.
	Each case pointed to another case in memory, who is not necessary stored right to them.
*/
List *initialization(void);
void insertion(List *list, int new_number);

int main(void){
	List *my_list = initialization();
	puts("before insertion");
	printf("%d\n", my_list->first->number);
	insertion(my_list, 5);
	puts("after insertion");
	printf("%d\n", my_list->first->number);
	puts("second insertion");
	insertion(my_list, 15);
	printf("%d\n", my_list->first->number);
	puts("next element, output should be 5 ?");
	printf("%d\n", *my_list->first->next);
	puts("last insertion");
	insertion(my_list, 35);
	printf("%d\n", my_list->first->number);
	puts("next element, output should be 15 ?");
	printf("%d\n", *my_list->first->next);
	free(my_list);
	
	return 0;
}

List *initialization(void){
	List *list = malloc(sizeof(*list));
	Element *element = malloc(sizeof(*element));

	if(list == NULL || element == NULL){
		exit(EXIT_FAILURE);
	} 

	element->number = 0;
	element->next = NULL;
	list->first = element;

	return list;
}

void insertion(List *list, int new_number){
	Element *new_elem = malloc(sizeof(*new_elem));
	
	if(list == NULL || new_elem == NULL){
		exit(EXIT_FAILURE);
	}
	new_elem->number = new_number;
	new_elem->next = list->first;
	list->first = new_elem;
}


