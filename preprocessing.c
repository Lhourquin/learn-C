#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

	preprocessing is when the compiler read all directive
	a directive is all instruction begining with the # symbol.
	for instance, the first thing compiler do, is to add the content of a file in the file where is called
	like this example: #include <stdio.h> ⬇️
	this instruction tell to the compiler: Import all the content of this file into the is called
	 so where we have #include <stdio.h>, all the code of this file is added, that why we can use 
	function of another file, or prototype etc.
	
	conclusion: the #include directive just doing insertion of the code of the file called on the file it called.
	if we want to call include library like stdio.h the syntaxt is: #include <stdio.h>
	if we want to call a file in the directory the project: #include "my-example-file.h"
*/

/*
	another directive is #define, this directive is like constant but not really at same time..
	#define allows you to define a preprocessor constant
	constant occupy a place in memory, #define directive not.
	#define directive is used to associate a value to a word.
	we can do this for instance: #define NUMBER_OF_LIFE 3
	first:	as we see, the syntax is different from constant, here we don't use = symbol
	second: const exist only on this context, when the function is finish, the constant is destroyed and not exist anymore,
	but the #define directive NUMBER_OF_LIFE always exist.So we can use it in all function we want, and in other file,
	most of the time is on .h file next to prototype
	so like the #include directive, the compiler at the preprocessing step will replace all occurence of NUMBER_OF_LIFE where is called on the code
	we will see on the code with a comment to explain that below.
*/

#define MAX_SIZE 100	
#define HEIGHT_WINDOW 23
#define WIDTH_WINDOW 60
//we can also add simple operation like * / + / - / %
#define PIXEL_NUMBER (WIDTH_WINDOW * HEIGHT_WINDOW)//good practice: operation should be always in parenthese to avoid problem and isolate this.
//we can also declare preprocssor constant without value
#define CONSTANT//the interest of do that it when the conditonal directive is used like will see below

#define HELLO() printf("Hello World!\n");
//macro: function we define in constant preprocessor, and we can call it in the file the preprocessing step of compilation will replace all HELLO() by the function we associate to.  the syntax is to add () to our macro.


#define MACRO_WITH_MORE_FUNCTION() printf("Hi\n");\
								   printf("My name is\n");\
								   printf("Slim Shady\n");

//macro that will take parametter
#define MAJORITY(age) if(age >= 18){\
							printf("you have the majority\n");\
					  }else{\
							printf("you don't have the majority\n");\
					  }
//preprocessor condition, the main interest to do that is to make conditional compilation, is really useful when we develop for mutliplatform and different OS. However, we will needed to compile for each of them.
#if condition
//if this condition is true, compile this
#elif condition_2
//else if compile this
#endif//end of condition

//check if constant preprocessor is define 
#ifdef CONSTANT
//do that if CONSTANT is define
#endif

#ifdef LINUX
//do that for LINUX is define
#endif

#ifdef MAC
//do that for MAC is define
#endif


//avoid infinite inclusion: what is infinite inclusion ?
/*
	Imagine:
	You have A.h and B.h 
	The file A.h contains #include "B.h",  therefore the file B.h is include on A.h
	But, and this is where it starts to get stuck, B.h might be contains A.h also, 
	that really common, the first file need the second file to work, 
	and the second file need the first file to work also.
	So, this what happen at the compilation:
		* The computer read A.h and see it does include B.h 	
		* Then, is read B.h to include, AND, it see he should include A.h
		* It include A.h in B.h , but in A.h it should include B.h
		* And it doe that again and agin
		* So it make it in infinite, after that the preprocessor stop and this is ruin the compilation.
	
	To improve this problem, we will use the #ifndef directive
	most used in .h file
*/
#ifndef DEF_FILE_NAME//if the constant is not define the file was never include
#define DEF_FILE_NAME//we define the constant, next time the file will be not include
/*
	content of the .h file (add all include and prototype, define directive etc)
*/
#endif
//ifndef conclusion
/*
	when is the first time for the preprocessor to read a file
	it read the condition if the constant DEF_FILE_NAME is not defined
	As is the first time and is not define, the preprocessor enter in the if conditon.
	and the first condition he will see if #define DEF_FILE_NAME
	now the constant is defined, the next time the file will be read,
	the preprocessor doesn't enter in the if condition, that avoid to re include all file each time the file is read.
	Most important thing is to define a unique name to constant preprocessor, otherwise that will make conflict.
	
	if we check the .h file in the standard library in system, we will see they all have this preprocessor condition to avoid issue
*/



int main(void){
	char string_1[MAX_SIZE], string_2[MAX_SIZE];//as MAX_SIZE is neither a variable nor a constant, we can add this between [] to define the length/siwe of the array of char. Because at the compilation in preprocessing step, is replaced by the value association to this workm here is 100	
	printf("%lu\n", strlen(string_1));
	printf("the preprocessor constant MAX_SIZE is equal to: %d\n", MAX_SIZE);//output the preprocessor constant MAX_SIZE is equal to: 100
	printf("PIXEL_NUMBER = %d\n", PIXEL_NUMBER);

	//predifined constant by the processor
	printf("__LINE__ to get the number of the actual line:%d\n ", __LINE__);
	printf("__FILE__ to get the name of the actual file: %s\n ", __FILE__);
	printf("__DATE__ to get the date where is compile: %s\n ", __DATE__);
	printf("__TIME__ to get the hour where is compile: %s\n ", __TIME__);
	//call macro
	HELLO()
	MACRO_WITH_MORE_FUNCTION()//notice: when we call macro, we don't add the symbol ; at the end.
	int age = 0;
	puts("How old are you ?");
	scanf("%d", &age);
	MAJORITY(age)
	return 0;
}
/*
	Conclusion:
	
		* preprocessor is a program/step in compilation who analyze the source code and make modification before compilation
		* #include directive insert the content of the file called
		* #define directive is a preprocessor constant allows replacement of the keyword in the code by these associate value
		* macro is a piece of code predefined with #define, it could accept parameter, we add parenthese. and don't add ; at the end when we called it on a function
		* It possible to use conditional preprocessor directive to choose what is compiled. (#if , #elif , #endif)
p		* TO avoid infinite inclusion with .h file, we use a comniation of preprocessor constant and condition (#ifndef)
*/
