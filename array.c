#include <stdio.h>

/*
   array are used to store a set of value
   when an array is created, it takes up contiguous space in memory: the boxes are one after the other.
   all case of this array have the same type. thus an array of int contains only value of type int and no other.

   Array == pointer ?

   Yes, because because when we call only the array, by default, we get the address of the value at the first index.

   Use variable to specify length ?

   we do this since C but not all compiler can do that, so the best way is to specify like thi array[5] or let the compiler do for us array[]
 */
int average_of_value_of_array(int result, int length);
int sum_of_value_of_array(int array[], int length);
void display_value_of_array(int array[], int length);
void display_value_of_array_2(int array[], int length);
int main(void){
	int i;
	//initialize array
	int array[4];//we define is brackets the lenght of the array
				 //we can initalize value like this
	array[0] = 9;
	array[1] = 7;
	array[2] = 0;
	array[3] = 3;

	int array_2[4] = {0 , 3, 4, 76};//or we can initialize value by the way
	int array_3[] = {3 , 4, 75 ,345, 365 ,65 ,56 };//and we can also just add [] without specify the length, the compiler guess the length of the array when it read data in, but if we declare with empty brackets [] without value after = that give us an error and it don't work
												   //initialize all value of an array by 0
	int array_of_zero[4] = {0};// we cannot iniate all value to another number like this array[4] = {1};
							   //the result will be -> 1, 0, 0, 0 only the first index will be equal to 1
							   //if we want to to that, we should make a loop to initialize automaicaly like this:
	int array_of_one[4];
	for(i = 0; i < 4; i++)	{
		array_of_one[i] = 1;//initalize each value in index by 1
		printf("the index %d of array_of_one is initialized to %d\n",i, array_of_one[i]);
	}

	for(i = 0; i < 4; i++){
		printf("value: %d\n", array_of_zero[i]);
	}

	printf("%d\n", *array);//display the first value in index 0 of array
	printf("%d\n", array[1]);//display the second value in index 1 of array
	printf("%d\n", *(array+1));//we can also do it like this, same as above
	for(i = 0; i < 4; i++){
		printf("%d\n",array[i]);
		printf("%d\n",array_2[i]);
		printf("%d\n",array_3[i]);
	}

	display_value_of_array(array_2, 4);
	display_value_of_array_2(array, 4);

	int array_of_number[9] = {8, 9, 12 , 8, 7, 11, 3, 9, 5};
	int result_array_of_number = sum_of_value_of_array(array_of_number, 9);
	printf("result %d\n", result_array_of_number);
	int average_array_of_number = average_of_value_of_array(result_array_of_number, 9);
	printf("%d average result average \n", average_array_of_number);

	int array_of_number_2[7]= {80, 75, 96, 82, 91, 87, 70};
	int result_array_of_number_2 = sum_of_value_of_array(array_of_number, 7);
	printf("result %d\n", result_array_of_number_2);
	int average_array_of_number_2 = average_of_value_of_array(result_array_of_number_2, 7);
	printf("%d average result average 2 \n", average_array_of_number_2);
	return 0;
}

void display_value_of_array(int array[], int length){//the best way to declare agr for array is like this int array[]
	int i = 0;
	for( i = 0; i < length; i++){
		printf("value is %p\n", &array[i]);
	}
}

void display_value_of_array_2(int *array, int length){//because an array is a pointer, we can pass it in argument like this int *array
	int i = 0;
	for( i = 0; i < length; i++){
		printf("value is %d\n", array[i]);
	}
}

int sum_of_value_of_array(int array[], int length){
	int sum = 10;
	printf("sum %d\n", sum);
	int i = 0;
	for(i = 0; i < length; i++){
		sum = sum + array[i];
	}
	return sum;
}

int average_of_value_of_array(int result, int length){
		
	return result / length;
}
