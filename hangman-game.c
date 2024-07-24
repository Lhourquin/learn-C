#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int read_char(char *str);
void clear_buffer(void);
void check_in_the_word(char letter, char *word_to_guess, char *answer_user, int move_player);

int main(void){
	puts("Welcome to hangman game!");
	
	int move_player = 10;
	char word_to_guess[5] = "WOOD";
	char answer_user[5] = "****";	
	char letter = 0;
	while(move_player != 0){
		printf("You have %d moves to play\n", move_player);
		puts("What is the secret words ?");
		int i = 0;
		for(i = 0; i < strlen(word_to_guess); i++){
			printf("%c", answer_user[i]);
		}
		printf("\nPropose letter: ");

		int result = read_char(&letter);
		
		if(result == 0){
			check_in_the_word(letter, word_to_guess, answer_user, move_player);
			move_player--;
			if(strcmp(word_to_guess, answer_user) == 0){
				puts("Yes !! You WIN !!!!");
				printf("The answer is well: %s\n", answer_user);
				break;
			}
		}else{
			putchar('\a');
		}
	}

	if(strcmp(word_to_guess, answer_user) != 0){
		puts("You loose.");
		puts("Looser.");
	}
	
	return 0;
}

int read_char(char *character){
	if(character != NULL){
		*character = getchar();
		if(*character == '\n'){
			return 1;
		}
		clear_buffer();	
		return 0;
	}else{
		return 1;
	}
}

void clear_buffer(void){
	int tmp = 0;
	while(tmp != '\n' && tmp != EOF){
		tmp = getchar();
	}
}

void check_in_the_word(char letter, char *word_to_guess, char *answer_user, int move_player){
	int i = 0;
	char tmp = 0;
	
	for(i = 0; i < strlen(word_to_guess); i++){
		if(word_to_guess[i] == letter){
			if(word_to_guess[i] != answer_user[i]){
				answer_user[i] = letter;
				break;
			}
		}
	}
}
