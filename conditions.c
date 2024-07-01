#include <stdio.h>

int main(void){ 
	//conditionnal structure (if, else, switch etc..)
	//if - else statements.

	/*
	   if - else if - else state is useful when we want to test in ranges, for instance by using some operator to compare value in if or else if condition.
	 */
	int number = 9;
	printf("if - else if: \t");
	if(number == 0){
		printf("the number equal 0\n");
	}else if(number < 9){
		printf("number is less than 5 %d\n", number);
	}else if(number > 9){
		printf("number is greater than 9 %d\n", number);
	}else{
		printf("number is %d\n", number);
	}

	/*
	   in if condition (or else if) we can use also && (AND) || (OR).
	 */
	printf("if used with ||:\t");
	if(number > 9 || number < 9){
		printf("Your number is not 9 %d\t\n", number);
	}else{
		printf("Your number is %d\n", number);
	}
	//switch case
	/*
	  here switch state is more useful when we need to test the value of variable or constant
	  so before using expression in switch we need to pre processing the value to test,
	  and store this value in variable, and after that use it for the switch statement.
	*/
	printf("switch statement:\t");
	switch(number){
		//case expression_to_test == 10://in a case, we add instruction if the case if true.
		case 10:
			printf("Your number is %d\n",number);
			break;//break stop the execution, if we don't add break, other case stil the reach the case instruction with break will be executed, that called "fall through"
		case 0:
			printf("Your number is 0.\n");
		default://good practice consist of declare it at first before other case.
			printf("Defaults instruction if nothing meet the corresponding case.\t\n");
			break;
	}

	return 0;	
}
