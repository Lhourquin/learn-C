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
void remove_in_list(List *list);

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
	puts("first element now");
	printf("%d\n", my_list->first->number);
	remove_in_list(my_list);
	puts("remove first element, the first number is replaced by 15");
	printf("%d\n", my_list->first->number);
	free(my_list);
	
	return 0;
}

List *initialization(void){
	List *list = malloc(sizeof(*list));//allowed memeory to list who attempt to store element
	Element *element = malloc(sizeof(*element));//element with number for the value and next for the pointer

	if(list == NULL || element == NULL){
		exit(EXIT_FAILURE);
	} 

	element->number = 0;//initalize value for number
	element->next = NULL;
	list->first = element;//first = {int number, Element *next}

	return list;
}

void insertion(List *list, int new_number){
	Element *new_elem = malloc(sizeof(*new_elem));//allowed memory to add new element
	
	if(list == NULL || new_elem == NULL){
		exit(EXIT_FAILURE);
	}
	new_elem->number = new_number;//new value for number of list (my_list->first->number)
	new_elem->next = list->first;//pointer to next value (NULL by default)
	list->first = new_elem;//new element on the list
}

void remove_in_list(List *list){
	if(list == NULL){
		exit(EXIT_FAILURE);
	}

	if(list->first != NULL){
		Element *to_remove = list->first;//value need to freeing in memory
		list->first = list->first->next;//next value swapped to the first removed
		free(to_remove);//free memory for the previous first value no longer need
	}
}

