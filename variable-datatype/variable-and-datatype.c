#include <stdio.h>
#include <string.h>

int main(void){
	printf("size of int: %lu\n", sizeof(int));
	printf("size of long: %lu\n", sizeof(long));
	printf("size of double: %lu\n", sizeof(double));
	printf("size of char: %lu\n", sizeof(char));
	
	//a good practice consist of make declaration of all variable at top of the function, and initialize it with a default value.
	//declaration of variable type int, depending on the computer, the int type will use 2 or 4 bytes.
	int area_of_square = 0;//will be stored in address like 0xF5000DA for instance. the area_of_square is like an alias for the address.
	//In C every variable is stored at a specific memory address. This address is unique a identifier where the data is located in memory (like we said before in 0xF5000DA for instance). the area_of_square acts as an alias or a label for the memory address where the actual integer value is stored.
	float  price = 125.99;
	signed char number_with_char_type = 120;//if the number is verry small and don't take more tham 128, we can use the type signed char to store it, instead using int that take 2 bytes we take only 1 byte. The result will be the letter x, which is the postion in ASCII table (120 = x)
	signed char letter = 'B';

	area_of_square = 12;//we can change the value of a variable, we don't need to specify their type, we have already declare before..
	int price_integer = (int)price;// sometime is usefull to get a float number and obtain just the integer part without decimal part. so price_integer = 125. This techniaue is called a 'cast'.
								   //we can print value of variable with printf function
								   // we can called the function one by one for each variable we want to display
	printf("area_of_square %d\n", area_of_square);
	printf("price %f\n", price);
	printf("price %.2f another way to display float number with flag to display only 2 digits after coma.\n", price);
	printf("number_with_char_type %c\n", number_with_char_type);
	printf("letter %c\n", letter);
	printf("price_integer %d\n", price_integer);
	// or we can also call one printf function and use the flag in order of datatype correspond to the variable, for instance:
	printf("\n");//the \n is as escape operator to break line, we also have for instance another escape opertor for tabulation : \t
	printf("area_of_square %d\nprice %f\nnumber_with_char_type %c\nletter %c\nprice_integer %d\n", area_of_square, price, number_with_char_type, letter, price_integer);
	/*
	   to display the corresponding value of the variable on printf we use flag with the symbol ' % '
	   %d : correspond to int type (integer number)
	   %f : correspond to float type (float number)
	   %c : correspond to char type (character)
	   %s : correspond to string type (array of character ??)
	 */

	//to declare variable we dont want that change in the future, we can use the keyword 'const', it very useful if we don't want change our variable, for examnle, the number PI is always 3.14, and nothing else. 
	const float PI = 3.14;//a n;ing convention in C is to UPPERCASE the name of the constant.	
						  //if we want to re assign PI with another value, we cannot, if we make it, the compiler return an error.
						  //PI = 5; give the result -->  error: cannot assign to variable 'PI' with const-qualified type 'const float'

	int number = 9;//earlier when computer was not so powerful like now, the register was used to store momentaly the variable on the register, so directly on the CPU, now we have computer more powerfull amd the compiler manage that for us.
	volatile int another_number = 10;//unlike register instruction, volatile indicates precisely that data does not be stored in register and only on the RAM. that useful earlier to but now, it also the compiler that manage that for us the most of time. It is mostly used for peripheric like keyboard or mouse cquse if we used register to manage it, it can triggers issue and cause some bug, the result can be to be impossible to use these peripheric, for instance the mouse. But now the comppiler and OS manage that automaticaly.

	//another tips: do not hesitate to give explicit name to variable, earlier when computer was not powerful, it is useful to name variable with the less word as possible to save the capital of memory, but now we don't have this problem and we can name variable with a long name to be explicit for us and other developer.
}
