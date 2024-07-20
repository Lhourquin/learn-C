#include <stdio.h>

int main(void){
	/*
	   when we declare variable, and initialize it,
	   we store the content of the variable,
	   for exeample: int age_user = 15, later when the compiler read the variable, it replace the variable by an adress in the memory of the computer.
	 */
	int age_user = 0;//good practice, init the variable with a value even if it change later.
	char letter[2] = "";//good practice, init the variable with a value even if it change later.

	//sometime we hear the scanf is not a good method to scan keybord data because is not safe, and it is true, but, that's not mean you cannot use it at all
	//just use it for the good purpose, C is a low level language, so we should be serious in the code and use apropriate method to do what we want for the use cqse.
	printf("Enter the letter you want.");
	scanf("%c", letter);
	printf("How old are you ?\n");
	scanf("%d", &age_user);
	/*
	   First step, we specify what it wait, number ? string ? char ? for this, we use the appropriate flag, for example, if the type of data await is number, we use %d.
	   Because we have more than one character, we should use the double quote ' "" ' .

	   To store the new value, we need to use the adress where the value of age_user is stored, for that we the symbol ' & ',
	   if we write age_user instead &age_user , we give in argument only the value, which is 0 now, but it's not that we want, 
	   we want to tell at the computer 'store in this adress the new value enter by user', so, 

	   in resume, to get the value of the variable/adress, 
	   we write only age_user, and in this case, we want to store the new value enter by user, so,
	   to get target the addres, we write &age_user ( ?????????? ).
	   ❌The only case when we don't use the & is for char type, will see that later. ❌
		Correction: scanf will take an address, so for array of (string) and other type of array, they already return the adress of the first elem, so we don't need to use the & symbol to specify we want the address, but for only one charm or int, we should use it.
		

	   If we don't use the ' &' we have this error : warning: format specifies type 'int *' but the argument has type 'int' [-Wformat] , 	
	   because when we use only age_user without the & before, it's just the value, not the adress where is stored in memory. (?????????)

		Also, the reason it say scanf is not securem is because we can enter another thing that it await, and modify the behavior of the program like that.
	 */
	printf("You enter the letter %s\n and your age is %d\n",letter, age_user);
	return 0;
	/*
		With this example, we see also we need to called in order what we want to display at the end,
		if i ask to the letter after the age, but at the end we display the letter before the age, then the program don't printf() for the letter,
		and we have just the result for the age like ' and your age is [n] ' istead of ' You enter the letter letter [letter] and your age is [n] '
	*/


}
