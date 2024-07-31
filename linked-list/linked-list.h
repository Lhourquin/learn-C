/*
=== Basic of Linked Lists ===

Node:
	- The basic unit of a linked list is called a "node"
	- Each node contains:
		* a value (data)
		* a pointer (or reference) to the next data in the list
Head:
	- The head is a pointer that points to the first node in the linked list.
	- If the list is empty, the head points to NULL or nullptr
Next:
	- In each node, the next pointer refers to the next node in the sequence.
	- The last node in the list has its next pointer set to NULL, indicating the end of the list.


=== Types of Linked Lists ===

Singly Linked List:
	- Each node points to the next node
	- You can traverse the list in one direction (from head to end)
Doubly Linked List:
	- Each node contains two pointers: one to the next and one to the previous node.
	- You can traverse the list in both directions (forward and backward)
Circular Linked List:
	- The last node points back to the head, forming a circle
	- Can be singly or doubly linked
*/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//Singly Linked List example
typedef struct Node Node;
struct Node{
	int value;
	Node *next;
};

typedef struct Linked_List Linked_List;
struct Linked_List{
	Node *head;
};

Node* create_node(int value){
	Node *new_node = malloc(sizeof(new_node));
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}

void add_new_node(Linked_List *list, int value){
	Node *new_node = malloc(sizeof(new_node));
	
	new_node->value = value;
	new_node->next = NULL;
	list->head = new_node;
}

void print_singly_linked_list(Linked_List *list){
	Node *actual = list->head;

	if(list == NULL){
		exit(EXIT_FAILURE);
	}
	
	while(actual != NULL){
		printf(" %d -> ", actual->value);
		actual = list->head->next;
	}
	printf("NULL\n");
}
#endif
