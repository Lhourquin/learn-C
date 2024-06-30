#include <stdio.h>

int main(void){
	/*
	   + (addition)
	   - (substrqction)
	   / (division) -> 5/2 = 2
		 * (multiple)
	 % (modulo) -> 5 % 2 = 1 the modulo is the operation given the rest of euclidien division by a given number.
				  to get the modulo, substract the divisor of the dividend until the result smaller than divisor
	
	important math rule : multiplication and divison have prioritie than addition and substraction, and operation in parenthesis have priority over all.
	BODMAS :
	- Brakets
	- Order (or indice (index ?))
	- Division
	- Multiply
	- Addition
	- substraction
	
	Division and multiplication, and addition and substraction, have the same priority , the convention is to work from left to the right when the order of operations would be unclear.
	Note: An alternative from of this mnemonic is BIDMAS, where the I stands for indices. PEMDAS ("Parentheses, exponents, ..") and BEDMAS are also used in the USA and Australia.
	so if we follows this rules : division can be done before multiplication and must be done before addition, and multiplication comes before addition.
	for instance : 20 * (100 + 1)
				we must first consider everithing in brackets, so we make 100 + 1 = 101.
				now we have 20 * 101 	
				the result is 2020.
	exampe 2: 4 + 5 * 3
			 first we consider multiplication before addition so we make
		     5 * 3 = 15
			so that guve us > 4 + 15 = 19, 
	exa;ple 3 :
		(4 + 5) * 3
		first we connsider everithing in penrenthesis so > (4 + 5) = 9
		so we have now 9 * 3 = 27
	 
	conslusion, like in math, these rules of priority is important to know ahen we apply arithmetic operation, 
	pathensis have the main priority over allm then multiplication/division/modulo and then additionm substraction.
	also, the ' = ' operators come after all, so when we assign a value, like this for example:
	
	int result_of_addtion = 2 + 3;
							^   ^ --> the operation is run, and after is affected to result_of_addition 		
		
	another example
	int number = 1;
	number += 1;
		   ^^ --> same as number = number + 1;	
	 */
	int player = 1;
	printf("Level : %d\n", player);
	
	player = player + 1;
	return 0;
}
