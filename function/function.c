#include <stdio.h>

int sum(int, int);
int init_ball(int);
void hello_world(void);

int main(void){
	/*
	   example of function:
	 * printf()
	 * scanf()
	 a convention consist of -> a function should do one things. 
	 a function take argument (like in printf, we take a string, and eventualy a variable to display it.)
	 a convention consist of add the keyword void in perenthese if function not have argument, in C ++ we don't need that, we can let prenthese empty.
	 also, we have a return value (0 in the main function most of the time ?) 
	 and we need to specify the return type by declaring before the name of the function the type which will be returned.

	 because C is procedural, we should declare function before the main function.
	 or, we can declare a prototype before, we don't need to specify the name of argument, just the type and the number of argument we wait, (in order ?) but is good practice and better,to add it for better understanding of what they doing.
	so if we want to add function after the main function we should use their prototype (?), that allow to not have error at compilation (?)

	 all C program should contain main function, and also all file should be encoded in utf-8 (on mac or linux, we have utf-8 with bom)
	 */	
	hello_world();
	int ball_x;
	int ball_y;
	printf("ball_x: %d\n", ball_x);
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^  -> no initialize why taht display a random number ??
	int result_of_sum = sum(12, 45);
	ball_x = init_ball(ball_x);
	ball_x = init_ball(ball_x);
	printf("print the result %d\n", result_of_sum);
	printf("ball_x: %d\n", ball_x);
	return 0;	//why we return 0 ??
}


int sum(int a, int b){
	int result = a + b;
	return result;
}

int init_ball(int pos_x){
	pos_x = 150;
	return pos_x;
}


void hello_world(void){
	printf("hello world :))\n");
}
	/*
	Scope of variable :
		Variable declared on a function have they value only in the function, that mean, 
		they exist only on this scope until it finish, after end of the function, it remove from the memory
		also, if in my function main i declare ball_x, and on another function i declare ball_x, it's not the same,
		but to be more understand, use another name is a good practice.
		
		here we can see init_ball, where the variable, pos_x = 150. then, the function return pos_x.
		after that, i called init_ball in the main function, i declare ball_x, and i add ball_x in argument.
		what they do ? Well, I took the variable to assignate the value of 150 as we can see on init_ball
		so the prupose of this function is to took the variable I given in argument, assignate the value of 150
		then return it.
		by do this, now on the main function, the variable ball_x equal 150.
		
		pos_x on the init_ball its just the arguent to take any variable i will give it.	
		and as we say, the ball_x is only avalaible on the main function, if i call it in another function, they doesn't exist.
		the locar variable exist till the function is on execution.
		a function is considred like a "context" a variable is specifuc to its context, when the context come to the end,
		the local variable is destroy.
	*/

