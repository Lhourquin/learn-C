#include <stdio.h>

int main(void){
	int i = 0;
	while(i != 20){//while loop: make iteration if the condition need to be true and stop when the condition is true
		i++;
		if(i == 20){
			printf("i -> %d, equal 20\n", i);
		}else{
			printf("I apear at each iteration  while %d not equal 20\n", i);
		}
	}


	do{//do something at leace once, and while the condition is not reach, it continue still is true
		printf("First execution and i apear at only once even the condition is already true because i -> %d already equal to 20 \n");
		i++;
	}while(i < 20);

	for(i=0; i < 20; i++){ //initialize  or re initialize the i variable, then add condition to make iteration, and increment for each iteration
		printf("BOUM\n %d\n", i);
	}
	return 0;	
}
