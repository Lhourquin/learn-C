#include <stdio.h>
#include <string.h>

/*

	In programation, string is like a text, we can retain this text in variable form
	Like we say earlier, a computer can retain only number, include letter. So how programmer can handle text ?
	This is what will see in this course. 
	
*/
char* concat(char str[],char str_copy[]);
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

	//get string from scanf	
	char name[100];
	printf("what's your name ?");
	scanf("%s", name);
	printf("Hi %s, i'm happy to meet you !\n",name);
	//get the lenght of the string
	printf("length of your name is %lu \n", strlen(name));
	//copy string 	
	char copy_name[100];
	printf("copy_name before %s\n", copy_name);
	strcpy(copy_name, name);
	printf("copy_name after %s\n", copy_name);
	//compare string
    int is_true = strcmp(copy_name, name);
	printf("%d\n", is_true);
	//concat string
	strcat(copy_name, name);
	printf("%s\n", copy_name);

    char result[100];
    concat(name, copy_name);
    printf("%s\n",name);
	//search char in string
	char sentence[100] = "A simple sentence to test strchr function";//already a pointer because it start at the char 'A'
	char *two_last_word_of_sentence = NULL;// new pointer because we get a part of this string in sentence, so we get the adresse of the char inside sentence
	char *word_after_simple = NULL;
	word_after_simple = strchr(sentence, 'e');
	two_last_word_of_sentence = strrchr(sentence, 's');// to find the last s char used in the string
	if(two_last_word_of_sentence != NULL && word_after_simple != NULL){
		printf("The two last word of sentence is %s\n", two_last_word_of_sentence);
		printf("The words after simple is %s\n", 	word_after_simple);
	}
	//find the first string include the char i want
	char *get_rest_of_sentence = NULL;

	get_rest_of_sentence = strpbrk(	two_last_word_of_sentence, "qwzto" );//return the rest of sentence when he find last char match one char of this arguments, here it's t sor the result will be "trchr function"
	printf(" sentence is: %s\n",	sentence );
	printf(" rest of sentence with qwzto argument is: %s\n",	get_rest_of_sentence );
	//search string in string
	char *rest_of_sentence_after_string_founded = NULL;		
	rest_of_sentence_after_string_founded = strstr(sentence, "test");
	if(rest_of_sentence_after_string_founded != NULL){	
		printf("string founded in sentence is: %s\n", rest_of_sentence_after_string_founded);
	}
	//write string with sprintf
	char new_string[100] = "TEST TEST TEST";//As I want to initialize it afterwards I must not add NULL herem otherwise i get this error : string.c:98:7: error: array initializer must be an initializer list or string literal

	int age = 56;
	printf("Before new initialization, new_string = %s\n", new_string);
	sprintf(new_string, "The string I wrote, and the number I want to add in the sentence %d", age);
	printf("My new_string variable contains: %s\n and I added to it the number or the variable age: %d\n", new_string, age);
	
	return 0;
}

char* concat(char str[],char str_copy[]){
    char new_copy[strlen(str) + 1];//length of the string + 1 for the \0
    //§char string_concat[100] = strcpy(str, str_copy);//https://stackoverflow.com/questions/44356121/why-am-i-getting-array-initializer-must-be-an-initializer-list-or-string-litera
    return strcat(str, str_copy);
}
