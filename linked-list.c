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
	Linked Linked_List:
	
	The Linked Linked_List is a way to organize a set of data in memory,
	That consist to gather structures by linked it between them by using pointer.
	A Linked Linked_List is an assembly of structure linked by pointer.
	Each element can contains what we want: one or many int, double, etc ..
	And of top of that, each element have a pointer to the next element.
	That form a list of pointer, that why is named Linked Linked_List
*/
/*
	Contrary of array, the elements of a linked list are not placed side by side in memory.
	Each case pointed to another case in memory, who is not necessary stored right to them.
*/
Linked_List *initialization(void);
void insert_at_begin(Linked_List *list, int new_value);
void remove_in_list(Linked_List *list);
void display_list(Linked_List *list);
void insert_in_end(Linked_List *list, int new_value, Node *pt_previous_elem);
Node* create_node(int value);
void add_new_node(Linked_List *list, int value);

int main(void){
	Linked_List *my_list = malloc(sizeof(*my_list));
	
	if(my_list == NULL){
		exit(EXIT_FAILURE);
	}

	Node *elem_list = create_node(56);
	puts("before insertion");
	//printf("%d\n", my_list->head->value);
	add_new_node(my_list, 45);
	puts("after insertion");
	printf("%d\n", my_list->head->value);
	print_singly_linked_list(my_list);
	free(my_list);
	
	return 0;
}
