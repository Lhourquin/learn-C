#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//int read_str(char *string, int str_len,FILE *pt_stdin);
int read_str(char *string, int str_len);
int read_char(char *character, FILE *pt);
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
/*
	printf("What's your name ?");
	scanf("%s", name);//in the example the output will be Kalu Thebest
	printf("Your name is %s\n", name);
	printf("Your name is %s\n\n", name);//output waiting: "Your name is Kalu Thebest", but will be: "Your name is Kalu" ! That's the problem..
*/
/*
	the scanf() function stop if they found a space or tabulation
	so they don't display the rest or your string !
	we cannot get the complete string if there contains space or tab
	
	the word "Thebest" is always in memory, in what we called "buffer"
	the next time we called scanf(), 
	the function scanf() read the word "Thebest", who is stay in memory,
	example below
*/
/*
	scanf("%s", name);//read the word Thebest after the escape
	printf("result name: %s\n", name);//output: Thebest
*/





	//example 2:
	//buffer overflow
	char first_name[5] = {0};
/*
	we allocate 5 case in memory, but if we put string with more longer lenght,
	it stil works aieth scanf() and this is the problem,
	scanf() function continue to write in memeory area doesn't allacate for this.
	The extra characters have overwritten other information in memory.
*/

/*

	printf("What is your firstname ?");
	scanf("%s", first_name);//enter sebastien, with more longer than 5 as we allocated before
	printf("Your firstname is: %s\n", first_name);//output sebastion working even if we have specify the length of 5 before
*/




/*
	why is dangerous ?
	
	because if the program don't manage this use case, 
	user can write what they want in the memory,
	he can add malicious code, to be executed by the program,
	this attack is called "buffer overflow",
	a famous attack but difficult to do (but still possible!)
	
	In this course, we will see how to prevent this type of vulnerability with another function we will learn.
*/
	//get string more safely
	
/*
	Many standard function allows to get string in C:
		* gets: read all the string but don't manage "buffer overflow"!
		* fgets: manage the number of character write in memory

	we will see how to use fgets() in replacement of scanf() !
*/

	//understand the principle of fgets()
/*
	prototype of fgets() function:
	
		- char fgets*(char *str, int num, FILE *stream);

	- *str: a pointer to an array allocated in memory where fgets will can write the string enter by the user.
	- num: the size of the array of string str, if we allocated an lenght of 10 to the array of char, fgets will read 9 char maximum, (it always reserve one case in memory to write \O at the end of the string).
	- *stream: a pointer to file to read, in our case, the file to read is the standard input, that mean the keyboard. to ask to read the standard input, we add in parameter the pointer stdin, who is automatically defined in the header of the standard library of C to represent the keyboard. However, it is possible to use fgets to read files, like we see earlier in the course about files.

	the function fgets() return:
		* the same pointer of *str if the function worked without error
		* NULL if we have an error
*/
	printf("Do you want to play a game with me ?");
	char user_response;
/*
	When we hit the keycaps "Enter" fgets keeps the '\n' corresponding to the hit of the keycaps "Enter"
	We can see that on the terminal because we have an aunderline after what we have enter in input.
	There's nothing we can do to stop fgets from writing the \n character, but nothing stops us from creating our own input function that will call fgets and automatically remove the \n character every time!
*/
	//without function
/*
	if(user_response != '\n'){
		fgetc(stdin);//consume the  \n to avoid fgets take it and pass the input for user_string
	}
*/
	read_char(&user_response, stdin);
	printf("Your response is %c\n", user_response);		
	//example fgets()
	char user_string[4] = {0};
	puts("Enter your name with 3 characters");
	//fgets(user_string, 4, stdin);

	read_str(user_string, 4);
	printf("You enter %s\n", user_string);
	return 0;
}

/*
void read(char *string, int str_len,FILE *pt_stdin){
	if(*string != '\n'){
		fgetc(pt_stdin);
	}
	fgets(string, str_len, pt_stdin);
}
*/

int read_char(char *character, FILE *pt){
	*character = fgetc(pt);
	printf("character: %c\n", *character);
	char user_input[3] = "";
	char *pt_extra = NULL;
	if(fgets(user_input, 3, stdin) != NULL){
		printf("user_input: %s\n", user_input);
		puts("too long");
		exit(0);
	}
	if(*character != '\n'){
		printf("character: %c\n", character);
		fgetc(pt);
		return 1;
	}else{
		return 0;
	}
}
int read_str(char *string, int length){
	char *cursor_pos = NULL;//declare the pointer to receive the address of the char we want to capture (in our case is \n)
	//read the text enter on keyboard
	if(fgets(string, length, stdin) != NULL){//check if we don't have an error and read input directly
		cursor_pos = strchr(string, '\n');//search the "Enter" char, and add the address of \n char
		if(cursor_pos != NULL){
			*cursor_pos	= '\0';//at the address, replace the value \n by \0, like this we avoid to fgets to write \n
		}
		return 1;//no error
	}else{
		return 0;//we have error, the result of fgets is NULL
	}
}
