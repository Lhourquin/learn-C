#include <stdio.h>

void cut_minutes(int *pt_hours, int *pt_minutes);

int main(void){
	int hours = 0, minutes = 120;
	int *pt_hours = &hours;	
	printf("value of hours before change it on pt_hours %d\n", hours);
	*pt_hours = 123;	
	printf("value of hours after change it on pt_hours %d\n", hours);
	printf("address of hours %p\n", &hours);
	printf("address of hours in pt_hours: %p\n", pt_hours);
	printf("value of hours in pt_hours: %d\n", *pt_hours);
	//send addresses of hours and minutes
	cut_minutes(pt_hours, &minutes);

	printf("%d:%d\n", hours, minutes);
	
	return 0;
}

void cut_minutes(int *pt_hours, int *pt_minutes){//in argument we declare type of the arguments is type in amd is a pointer, like we made to declare a pointer.
	*pt_hours = *pt_minutes / 60;//the * before is to change the value content in the address pass in argument.
	*pt_minutes = *pt_minutes % 60;
}
