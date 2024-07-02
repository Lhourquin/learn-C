/*
	Why main() ?

	C program always have at minimum one function, this function is called main().
	This is the first instruction executed when the system trigger the start of the program.
	main is not really a keyword, but is the keywoard of a necesary function should ne existed in every C main file.
	unlike all other function you didn't need to declare main by a prototype.
	
	Because it's a function, the name of the function must be followed by two parenthese () {even is empty} but is good practice to use void in this by convention,
	and a couple of brackets (even empty to), intended delimited the block of instruction.
	If we compile this type of code, we will see nothing, no error and no result.

*/

int main(void){
//^--> Why the keyword int before the name of function ? Because it specify when it compiled by the compiler the type of value is returned by the function.
	return 0;
/*
	Why return 0 ?
	
	To comply with the protocol, it recommended to make sure when the program ends, it return a numerical value to the operating system.
	the value is a integer: 0 if all it's succesfully done, otherwise another value is returned, the value help the system to be informed about the type off issue encounted.
	By convention, the value returned is 0, It is used to confirm the program as be executed without any problem.
	A value greater than 1 warned about an error but it also signify the specific result of a treatment.
	
*/
}