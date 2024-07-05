#include <stdio.h>

int main(void){
	int age = 10;//this line mean: create variable of type int with the number 10 for value.
	printf("Here I show the content of age variable: %d\n", age);//display the value
	printf("Here I show the pointer of age variable with the pointer flag and the ampersound to target the address (&age): %p\n", &age);//display in hexdecimal format
	printf("Here I show the pointer of age variable with the digit flag and the ampersound to target the address (&age): %d\n", &age);//display in decimal format
	/*
		with 'age' only, the computer read the value of the variable in the memory and return it.
		with '&age' the computer, the computer say to us what is the address where the variable i sotored in memory.
	*/
	int *my_pointer_age = NULL;//this line mean: create variable of type pointer
	my_pointer_age = &age;//this line mean:add to this variable of type pointer.The value is the address of the oage variable.
	//notice we don't have the keyword like int or double for the type of pointer, instead we specify also the type like int or other and we use the symbol * 
	
	printf("%d", my_pointer_age);//without the * symbol, the value of my_pointer_age is the addres of age variable.
	printf("%d", *my_pointer_age);// to get the value of the age variable where the address is indicated on, we should use the symbol * at prefix.This allow us to have access of the value of variable age. if we use the & symbol at prefix, we get the address of the pointer itslef.
/*
	When the pointer is created, the operating system reserves a case in memory like it doing for the variable age. The diffrence here, is that the value of my_pointer_age is little special. The value of my_pointer_age is the address of the variable age. 

	Main Principle of pointer
	On a variable like age:
		* age -> "I want the value of the variable age"
		* &age -> "I want the address where the variable age is stored"	
	On a pinter like my_pointer_age:
		* my_pointer_age -> "I want the value of my_pointer_age(which is an address)"
		* *my_pointer_age -> "I want the value of the variable in the address in my_pointer_age,so where the age variable is stored, so I want to get the value of age"
*/	
/*
	Be awarre to not confuse different syntax:
		* When I declare a pointer variable like this int *my_pointer; That's mean I want to create a pointer.
		* When I use this pointer, if I use only my_pointer wihtout * symbol, I get the value of my_pointer so the addres of the variable I target. So that's mean I want to get the address where my pointer target.
		* And to get access of the value of the address in my_pointer, I use * at prefix of my_pointer, like that *my_pointer, that mean I want the value of variable on the target address in my pointer.
*/
/*
	Conclusion:
	* Each variable are stored in an specify adress in memory
	* Pointers stand like variable,but instead of stored number, they store the address where the variable targeted is in memory.
	* If we put the & symbol before the name of the variable, we get they address instead of value.
	* If we put the * symbol before the pointer, we get the value sotrd at the address target by the pointer.
*/
	
	return 0;
}
