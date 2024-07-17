#ifndef STRUCT_H
#define STRUCT_H

struct Coordinates{
	int x;//Abscisses
	int y;//Ordonates
};
typedef struct Another_coordinates Another_coordinates;
/*
	typedef indicate will created a alias structure
	struct Another_coordinates is the name of the structure we want to create an alias
	Another_coordinates alias
	
	So this line tell: writing the word Another_coordinates is like writing struct Antoher_coordinate

	By do this we don't need to reuse the word struct in struct.c (or another file we called struct.h)	
*/
struct Another_coordinates{
	int x;
	int y;
};
#endif
