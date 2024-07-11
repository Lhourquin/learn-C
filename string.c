#include <stdio.h>

/*

	In programation, string is like a text, we can retain this text in variable form
	Like we say earlier, a computer can retain only number, include letter. So how programmer can handle text ?
	This is what will see in this course. 
	
*/
int main(void){
/*
	use the type char to store character
	if char can store number between -128 and 127, we rarely use char for this in C.
	char allows to stored number from -128 to 127, with unsigned char we can store number from 0 to 255
	Usualy, even if the number is little, we stored it on type int.certainly that take more memory, but nowaday,it's realy not that missing on a computer.
	
	the type char is planned to store only one char, be aware, only one char. The memory can store only numberso we inventde a table that made convertion between number and letter,
	Thus, the table indicate the number 65 equal the letter A.
	The C language allows to make esealy the translation letter to the appropriate number
	To get the number associated to the letter, we have to write this letter between ' ' like this 'A' 
	At the compilation, the 'A' will be replaced by the coresspondant value.
	
*/	
	char letter = 'A';

	printf("%c\n", letter);//print the letter 
	printf("%d\n", letter);//print the number that corespond to the letter (here is 65 for A)
	/*
		note: the a not equal A in the ASCII table, the computer is case sensitive
		mostly character "basic" are code  between 0 and 127, the table make the conversion between number and letter.
		The computer use the ASCII table to convert letter to number and vice versa
		we can use char to store only one letter
		'A' is replaced by the correspondant number value at compilation (here is 65) we ' ' to get the value of letter
	*/
	char string[5] = {65, 66, 66, 65};//this array of number with type char return the letter assiociate to their number, here we have A B B A
	char another_string[7]= {'q', 'w','e','r','t','y', '\0'};//if we use directly letter like this, we must add \0 at the end, to tell at the computer to stop reading.
	//so like we see    ^  above even if the length of the word qwerty is 6, at the end we add \0, so we specify the length of 7
	//we can also not specify the length and let the compiler manage that for us.
	//caution! no forgot to add the \0 at the end, is it a common source of error in C.
	printf("%s\n", string);//print ABBA
	printf("%s\n", another_string);//print qwerty
	//to display correctly, we use the flag %s to specify we wait a string
	
	//another way to declare and initialize a string is this syntax below
	char another_string_without_curly_brackets[] = "qwerty";//by the way the compiler will automaticaly calculated by the compiler,
	//then, it write step by step the letter of the word "qwerty" in memory,   it count letter and add\0 by itself 
	//but there is a flaw (there always flaw.. 🤖) that don't work at the initialiization only, when we have declared before
	//exemple: another_string_without_curly_brackets = "qwerty";//don't work
	printf("%s\n", another_string_without_curly_brackets);//print qwerty
	return 0;
}
