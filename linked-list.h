#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Element Element;
struct Element{//will be element of the list
	int number;
	Element *next;
};

typedef struct List List;
struct List{//the list who have element
	Element *prime_number;
};

#endif
