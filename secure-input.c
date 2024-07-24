#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//int read_str(char *string, int str_len,FILE *pt_stdin);
int read_str(char *string, int str_len);
int read_char(char *character, FILE *pt, int length);
void clear_buffer(void);
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
/*
	char name[20] = {0};
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
/*
	printf("Do you want to play a game with me ?(y/n)");
	char user_response = fgetc(stdin);
*/
/*
	When we hit the keycaps "Enter" fgets keeps the '\n' corresponding to the hit of the keycaps "Enter"
	We can see that on the terminal because we have an aunderline after what we have enter in input.
	There's nothing we can do to stop fgets from writing the \n character, but nothing stops us from creating our own input function that will call fgets and automatically remove the \n character every time!
*/
	//char user_string[4] = {0};
	//without function
	//if(user_response != '\n'){
	//	if(user_response == 'y'){
	//		fgetc(stdin);//consume the  \n to avoid fgets take it and pass the input for user_string
	//		puts("Enter your name with 3 characters");
	//		read_str(user_string, 4);
	//		printf("You enter %s\n", user_string);
		//}else{
		//	exit(0);
		//}
	//}
	//puts("Good Bye.");
/*
	BUFFER

	fgets function is secure, so when we write a text more longer than specify, it stop to read at the limit of length planned.
	for example:
*/
	char name[10] = "";
	puts("What is your name ?");
	read_str(name, 10);//if we put Jean Edouard Albert 1er will "Jean Edou" (length of 10 so it take 9 char and the last char will replaced by \0) the rest will not display and not stored in name.

	//clear_buffer();	
	printf("name: %s\n", name);//output Jean Edou instead of Jean Edouard Albert 1er enter by user
	puts("What is your name ?");
	read_str(name, 10);///if we put Jean Edouard Albert 1er will "Jean Edou" (length of 10 so it take 9 char and the last char will replaced by \0) the rest will not display and not stored in name.
	printf("name: %s\n", name);//output Jean Edou instead of Jean Edouard Albert 1er enter by user
/*
	The problem, the rest of the string who cannot be read, as know "ard Albert 1er" will not disapear: 
	is stay in BUFFER.
	
	The "buffer" is a memory zone who receive directly input from keyboard who serves as an intermediary,
	between the keyboard and the array to store data input.

	In C, we have the pointer to the "buffer": stdin
	
	explanation step by step:
		* the use write this string on the keyboard
		* this string is tranfered by the operating system to the buffer stdin
		* the function fgets() tranmit this string in the memory zone and remove what they read of the buffer.
	
	When the user write text on keyboard, the operating system copy directly the text writing on the buffer "stdin".
	The buffer is here to receiver temporary the input from keyboard.
	
	the role of the function fgets() is to extract from the buffer character in it, 
	and copy them in the memory zone indicate, our array name.
	
	Then after the copy is done, fgets remove from the buffer everithing it may have copy.
	
	If everything went well, fgets was able to copy the entire buffer into your string, 
	and then the buffer will be empty at the end of execution of the fgets() function.
	BUt, if the user enter more characted than planned, and the function fgets can copy only one part of them,
	only read character will be remove from the "buffer". All of these don't read part stay it on the buffer !
	
	This is why if we re call the function after, is the previous input was too long, 
	the rest of the string will be take by fgets because is always on buffer.
	so by this, we cannot write anything because fgets will take the rest of the last input stay in buffer.	
	
	So fgets protect us to the buffer overflow, but traces always remain in the buffer if there are too many

	we should improve that by creating a function to handle that
*/
	
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

int read_str(char *string, int length){
	char *input_pos = NULL;//declare the pointer to receive the address of the char we want to capture (in our case is \n)
	//read the text enter on keyboard
	if(fgets(string, length, stdin) != NULL){//check if we don't have an error and read input directly
		input_pos = strchr(string, '\n');//search the "Enter" char, and add the address of \n char
		if(input_pos != NULL){
			*input_pos	= '\0';//at the address, replace the value \n by \0, like this we avoid to fgets to write \n
		}else{
			clear_buffer();
		}
		return 1;//no error
	}else{
		clear_buffer();
		return 0;//we have error, the result of fgets is NULL
	}
}

void clear_buffer(void){
	int tmp = 0;
	while(c != '\n' && c != EOF){
		tmp = getchar();//temp variable to receive char from the buffer until we encounter \n or EOF
		printf("c: %c\n", c);
	}
}
