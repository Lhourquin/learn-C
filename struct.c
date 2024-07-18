#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
/*
	In C, when we make a complex project, we can create our type of variable.
		* structure
		* enumeration
	
*/
void initialize_coords(int *pt_x, int *pt_y, int x,int  y);
void another_initialzer_coords(Another_coordinates *coords, int x, int y);
int main(void){
//structure
/*
	What is a struture ?
	

	A structure is a set of variable could have different types.
	Unlike an array, is not obligatory to have all data of a same type,
	you can create a structure including variable of type, char, int and double at the same time.
	struct is generaly define in .h file, like prototype and defines directives.
	
*/	
	//to define a struture we use the keyword struct before the name of the structure
	struct My_structure_example{
		int number;
		int number_2;

		double decimal_number;

		char letter;
	};//a good practice consist of follow the same rules for syntax declaration of variable, but we Uppercase the first letter.
	//it useful for example if we work in 2D with two axis
/*
	struct Coordinate{
		int x;//Abscisses
		int y;//Ordonates
	};
*/
	struct Coordinates point;//create variable point of type Coordinates. Always use struct keywoard to specify at the computer is a custom type, like Coordinates. But is a litlle bit painful to do that, so devevelopper invented 'typedef', it is what we used for Another_coordinates.
	point.x = 32;
	point.y = 20;	
	printf("point x: %d\n", point.x);
	printf("point y: %d\n", point.y);

	Another_coordinates another_point;//as declared the struture with an alias strutcture in struct.h with a typedef instruction, so we don't need to use keyword struct before here/
	another_point.x = 100;
	another_point.y = 300;
	printf("another_point x: %d\n", another_point.x);
	printf("another_point y: %d\n", another_point.y);
	
	//struct can contains array
	struct Person{
		char first_name[100];
		char last_name[100];
		char address[100];
		
		int student;//Boolean: 1 = student, 0 = not student.
		int age;
	};
/*	
	This struture is composed by 5 sub variables. 
		* The first three have char type to store fist_name, last_name, and address.
		* The last two have int type to store age and Boolean to check if is sutdent or not.
	Not limit of variable if we want to add variable in structure to complete him.
*/	

/*

	struct Person user;
	printf("what is your first name?\n");
	scanf("%s", user.first_name);
	printf("what is your last name?\n");
	scanf("%s", user.last_name);
	
	printf("Your first name is %s and your last name is %s\n", user.first_name, user.last_name);
	struct Person users[2];
	
	printf("what is your first name?\n");
	scanf("%s", users[0].first_name);
	printf("what is your last name?\n");
	scanf("%s", users[0].last_name);
	
	printf("Your first name is %s and your last name is %s\n", users[0].first_name, users[0].last_name);

	printf("what is your first name?\n");
	scanf("%s", users[1].first_name);
	printf("what is your last name?\n");
	scanf("%s", users[1].last_name);
	
	printf("Your first name is %s and your last name is %s\n", users[1].first_name, users[1].last_name);
	printf("first user named %s and this last name is %s, the second user is %s and this last name is %s\n", users[0].first_name, users[0].last_name,users[1].first_name, users[1].last_name );

	Player players[2];
	size_t number_of_players = sizeof(players) / sizeof(players[0]);
	printf("%zu\n", number_of_players);
	int i = 0;
	for(i = 0; i < 5; i++){
		int number_user = i + 1;
		printf("name of player %d\n",number_user);
		scanf("%s",players[i].name);
//		printf("Name of the player %d is %s\n", number_user, players[i].name);
	}
	
	for(i = 0; i < 5; i++){
		int number_user = i + 1;
		printf("Name of the player %d is %s\n", number_user, players[i].name);
	}


*/


	//init structure
/*

	Like variable, pointer and array, is recommended to initialize it at creation 
	this avoid garbage value or random data in it. When we declare variable without value,
	this variable take what they found in memory, where is placed. Sometimes is 0,
	sometimes is a residue of another program who run before, that why if we print the non inialized variable,
	we have value with non sense like -93824 or 123428357 etc.(I'm asked earlier in a file, know I know why !!!!!!!!!!!!)

	How we initialize a:
		* A variable: with 0 (the most simple case)
		* A pointer: with NULL, NULL is a #define located in <stdlib.h> who generaly equal to 0,
		but we continue to use NULL by convention for a pointer to clearly see that a pointer and not an ordinary varaible.
		* An array: each value to 0.
		* A struct: looks like a litle bit of an array.
	
*/
	//for instance
 	Another_coordinates coords = {0,0};
	/*
		That define in order:
			- coords.x = 0;
			- coords.y = 0;
	*/


	//use pointer on a struct
	
	
	initialize_coords(&coords.x, &coords.y, 23, 45);//by using variable of a struct, nothing change, we make like we see earlier
	printf("coords_initialized.x %d\n", coords.x);

	Another_coordinates another_point_2 = {0,0};
	another_initialzer_coords(&another_point_2, 90, 34);//that really interesting, here, we send directly the address of the struct of Antoher_coordinates type.
	printf("antoher_point_2.x: %d\n", another_point_2.x);
	printf("antoher_point_2.y: %d\n", another_point_2.y);

	//enum
	Volume sound = MEDIUM;//as we define in struct.h, we initialize a variable of type Volume, and we choose to use MEDIUM
	printf("sound: %d\n", sound);
/*  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	output is 1, why ? 
	First, notice the ressemblence with the use of preprocessor constant, is similar but not exactly the same thing.
	The compiler associate automatically a possible value for variable in the enum type.
	In the case of our Volume enum type:
		* WEAK = 0
		* MEDIUM = 1
		* STRONG = 2
	The automatic initialization begin at 0.
	
	Unlike define, is the compiler himself who initialize MEDIUM to 1.
	And not the preprocessor (first step of compilation)
	At the end, is the same thing
	When we initalize sound to MEDIUM, we add the value 1 in the memory case.
	
	It's useful to know if MEDIUM = 1 or WEAK = 0 ?
	Not really. the compiler associate the value for us automatically, so when we use is in a comparison, we can write this:
*/
	if(sound == MEDIUM){//is really useful, because that allows for us to write clearly code like this, no matter the value will be.
		puts("sound is medium.");
	}else{
		puts("sound in not medium.");
	}

//value associated directly at dlecaration of enum type Another_volume
	Another_volume video_sound = MEDIUM_2;
	printf("video_sound: %d\n", video_sound);

	return 0;

	
}

void initialize_coords(int *pt_x, int *pt_y, int x, int y){
	*pt_x = x;//access to the variable of the pointer to assignate the value we want
	*pt_y = y;
}
void another_initialzer_coords(Another_coordinates *coords, int x, int y){//here in arguments, we add the type of the pointer
	(*coords).x = x;//first syntax: we cannot do like a simple variable, here we need to use perenthese, because if we use just the point like in variable, we apply a separation on the word coords and not on coords entirely. What we want, is to access at *coords to modify they value
	coords->y = y;//second and most used syntax, we can use this syntax only on a pointer, not on normaly variable.
}


/*
	Conclusion:

	 	* struct is a type of variable we can customize, unlike predifened type, we need to define by oursleve.
		* a struct is composed by subvariable generally with basic type like int, char, double etc. even array.
		* we can access to this variable of the struct by separate the name of the variable of the type of struct by a pont '.'
		* if we handle a pointer, we use these syntact:
			- (*pt).x
			- pt->x (the best and most used)
		* an enum is a type of custom variable who can take only one of predefined value like: WEAK, MEIDUM, STRONG for instance.
*/
