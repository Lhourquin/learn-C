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

typedef struct Player Player;
struct Player{
	char name[100];
};

//enum
/*
	enum is a different way to create our custom type fo variables.
	enum not have sub variable like a struct.
	enum take only one case in memory,
	and this case can take one of value you define (at only once)
*/
//example
typedef enum Volume Volume;
enum Volume{
	WEAK, MEDIUM, STRONG
};
//associate a specific value to our variable
/*
	Why is useful to associate specific value in enum ?

	Becaus, like ine the case of Volume, if on the computer the volume is handle between 0 and 100, it is useful to associate a specific value to each element
*/
typedef enum Another_volume Another_volume;
enum Another_volume{
	MUTE = 0, WEAK_2 = 10, MEDIUM_2 = 50, STRONG_2 = 100
};
//If we not define the next element, it will be equal to the value of the previous element + 1
//we need to create new name of variable, we cannot use the same in another enum type ??
#endif
