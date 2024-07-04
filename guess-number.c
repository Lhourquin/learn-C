#include <stdio.h>

int main(void) {
	char answer;//char value must be declared with '' and not "", the quotation marks is for string.
	int number = 5;
	int value = 'y';
	printf("Do you want play a game with me ? (y/n)");
	scanf("%c",&answer);
	switch(answer){
		case 'y':
			while(value != number){
				printf("Guess the number (type 0 if you want to stop the game)");
				scanf("%d",&value);
				if(value != number && value != 0){
					printf("You typing the wrong number\n");
				}else if(value == 0){
					printf("GoodBye.\n");
					break;
				}else{
					printf("Cool, you guess the right number.\n");
					break;
				}
			}
			break;
		case 'n':	
			printf("Oh no.\n");
			break;
		default:
			printf("Bye.\n");
			break;
	}
	return 0;
}

