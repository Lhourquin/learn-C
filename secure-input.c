#include <stdio.h>
#include <stdlib.h>
/*
	sucure input:
	
	untill now we using scanf() to allows enter text and response to our question,
	but what they assure the user response like we wainting ?
	the purpose of this course is discover the problem of the scanf() function,
	and use the alternative more safe: fgets() function
*/
int main(void){
/*
	understand limitation of scanf() function:

	scanf() is a double-edged function:
		* it's easy to use them at begin (this why use them still now).
		* but this behavior is complex, they can be dangerous in some use case.
	
	let see the limit with two concrete example.
*/
	//example 1:
	char name[20] = {0};

	printf("What's your name ?");
	scanf("%s", name);//in the example the output will be Kalu Thebest
	printf("Your name is %s\n", name);
	printf("Your name is %s\n\n", name);//output waiting: "Your name is Kalu Thebest", but will be: "Your name is Kalu" ! That's the problem..
/*
	the scanf() function stop if they found a space or tabulation
	so they don't display the rest or your string !
	we cannot get the complete string if there contains space or tab
	
	the word "Thebest" is always in memory, in what we called "buffer"
	the next time we called scanf(), 
	the function scanf() read the word "Thebest", who is stay in memory,
	example below
*/
	scanf("%s", name);//read the word Thebest after the escape
	printf("result name: %s\n", name);//output: Thebest

	//example 2:
	//buffer overflow
	char first_name[5] = {0};
/*
	we allocate 5 case in memory, but if we put string with more longer lenght,
	it stil works aieth scanf() and this is the problem,
	scanf() function continue to write in memeory area doesn't allacate for this.
	The extra characters have overwritten other information in memory.
*/

	printf("What is your firstname ?");
	scanf("%s", first_name);//enter sebastien, with more longer than 5 as we allocated before
	printf("Your firstname is: %s\n", first_name);//output sebastion working even if we have specify the length of 5 before
/*
	why is dangerous ?
	
	because if the program don't manage this use case, 
	user can write what they want in the memory,
	he can add malicious code, to be executed by the program,
	this attack is called "buffer overflow",
	a famous attack but difficult to do (but still possible!)
	
	In this course, we will see how to prevent this type of vulnerability with another function we will learn.
*/
	
	return 0;
}
