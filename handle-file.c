#include <stdio.h>
#include <stdlib.h>
/*
	Variable exist only on the memory (RAM)
	once the program is finsih, the variable is destroy,
	and is not possible to retrieve the value.

	To read and write on a file we need to use standard library:
		* stdio
		* stdlib
*/
int main(void){
/*
	Open a file with fopen():
	
	Each time we want to open a file, that is for read or write,
	we need to do:
		* call the function fopen() who return a pointer of the file
		* Check if itis openned (that mean, if i exist) by cjeck the value of the pointer receveid.
	
	The protoype of fopen():
	FILE* fopen(const char *name_of_file, const char *open_mode);
	
	This function await two parametters:
		* the name of the file to open
		* the mode to open this file, an indication to tell what we want to do with it: read, write, read+write, only read, only write etc.
	
	this function return a pointer on FILE (a structure of type FILE defined in stdio.h) which return FILE*
	Is necessary to get the pointer to be able to read and write in the file.
	
*/
	FILE *file = NULL;//it is fundamental to initialize a pointer to NULL if we don't have a value to give.
	//Is not necessary to use struct keyword, the developers of stio.h made that for us, with a typedef.
	//the shape of this structure can change from OS to another,  that will not contains the same sub variables in all.
	//we never change directly the FILE (we don't make my_file.elem for example).
	//we use a function that handle that for us instead.

/*
	How to use the second parametter ? (open mode):

		* "r": mode to read only. The file need to be created beofore.
		* "w": mode to write only. If the file doesn't exist, is created.
		* "a": mode to write at the end of file.If the file doesn't exist, is created.
		* "a+": mode to read and write at the end of file.If the file doesn't exist, is created.
		* "r+": mode to read and write. The file need to be created beofore.
		* "w+":  mode to read and write with suppression of all content of the file. The file is empty at first, then you can write, and read after taht.If the file doesn't exist, is created.
("r" = read, "w" = write, "r+" = read and write, will be used most of the time.)
	
	if we want to read only on the file, even if "r+"can both read and write, we should use the "r" because by do this we sure that not accidentaly write something we didn't want to write, that assure we not modify a file we don't want to modify.
	The "w+" is more dangerous, because he can remove content we didn't want to remove without a confirmation before, it should be used only if we want to reset a file before writing in.


*/
	file = fopen("file.txt", "w+");//open a file to read and write in it. the pointer file will be a pointer on file.txt
/*
	Where should be file.txt ? 
	
	Generaly in the same directory with the exec file. It should be of any type.
	Can also be in another directory, in sub directory, it called relative path.
	Can also be everywhere on the disk, in this case, you should write the entire path (called absolute path)
	example in windows(absolute path): 
		file = fopen("C:\\ProgramFiles\\Notepad++\\readme.txt", "r+");
	this code open a file placed in C:\ProgramFiles\Notepad++ (we need to use double back-slash in the code, otherwise the computer will do interpreted the \ like a escape sequence  )
	the problem with this approach, it is not portable from an OS to another, in UNIX like system, the file system is different, and it used slash / , for example:
		file = fopen("/home/username/dev/app-project/readme.txt", "r+");
	it reommend to use relative path instead.	
*/
/*
	the pointer file should contain the address of the data structure type FILE who describe the file.
	it is charged in memory by fopen for us by fopen() function.
	At this step we have two possibilities:
		* The file is open, so file not equal NULL and we can start to read and write it.
		* The file is not open, the openned as failed so is already equal to NULL, and we cannot do anything in the file.
		Maysbe because the file is used by another program, etc, we don't continue to work with them.
	
*/
	if(file != NULL){//we can read/write on the file
		char city[100];
		char name[100];
		int age = 0;
		puts("file opened");
		//fclose(file);//when we have finish to work with a file, we closed it. The role of this function is to freeing the memory after we finish to work with.
/*
	fclose();
	this prototype: int fclose(FILE* pt_on_file);
	this function take one parameter, the pointer on the file.
	it return a int who return if the file is succesfully cloed:
		* if it's succesfull, the output is 0
		* if it's failed, the output will be EOF. EOF is a define directive defined in stdio.h who correspond to special number, who tell, either is reached the end of the file, or it's an error.
*/
/*
	GOOD PRACTICE fclose()
	
	Always think to close file in program when we done with it. That allows to freeing memory.
	If we forgot to do this, the program will take a lot of mememory, very too much that they need and don't use!
	On a big project that can be a really big problem.
*/
		/*
			we will see three way to write on a file:
				* fputc: write one character in the file (only one character at time ).
					- prototype: int fputc(int character, FILE* pt_on_file);
				* fputs: write a string in file.
					- prototype: char* fputs(const char* string, FILE* pt_on_file);
				* fprintf: write a formated string in file.
		*/
		//fputc
		printf("What's your name ?");
		scanf("%s", name);
		fprintf(file,"Your name is %s\n", name);
		puts("How old are you ?");
		scanf("%d", &age);
		fprintf(file, "You have %d years old\n", age);
		puts("Where are you from ?");
		scanf("%s", city);
		fprintf(file,"You're from %s\n", city);
		fclose(file);
	}else{//we cannot read and write in the file
		puts("file not opened");
		int error_response = fclose(file);
		printf("error fclose response: %d", error_response);
	}

	
	return 0;
}

