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

int main(void){
	List *my_list = initialization();
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
