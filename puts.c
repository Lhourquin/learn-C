#include <stdio.h>

/*
	The standard function named puts() return a stream of text to the standard output -> stdout(by defaults, is the screen)
*/

/*
	What means stream and output ?
	
	For the moment considering the role of puts() function is to display test on the screen in line one by one.
	We have a generic syntax where we use the function like this:

		int puts(const char *s);
	
	For now we simplify the syntax by using puts() like this:

		puts("My text");

	The text part must be a string, that means letter and digit between two quotation marks, used to like a delimiter.
	We can indicate also a variable name, we will se that later.
	We can use the puts() function at the condition by informing the compiler about this prototype such as in another pre definate file,
	The header file stdio.h . The header file is incorporate by the #include directive at the first line in the top of the file.
	
	The C languange manages text in Input and Output, in a form of data stream, a concept we will see later.
	The standard output peripheric is usualy the the screen, but it can be also redirect to a file of hard disk by the operating system,
	or the printer etc. This is why the puts() function is describe to send the data to standard output, not especialy the screen.
	
*/
int main(void){
	printf("Another text\a\n\t");//mean print formated
	printf("Another text\b");//mean print formated
	printf("Another text\f");//mean print formated
	printf("Another text\n");//mean print formated
	printf("Another text bim bam boom \r");//mean print formated
	puts("My text\a");//mean put string
	printf("\"bonjour\" dit le corbeau!\n");
	char person[10];
	puts("Who are you ?");
	fgets(person, 10, stdin);
	printf("Happy to encounted you, %s.\n", person);

	return 0;
}
