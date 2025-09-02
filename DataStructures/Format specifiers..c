#include <stdio.h>
int main(){
	float item1=52.00;
	float item2=24.45;
	float item3=65.21; 
	
	//%.1 decimal precision
	//%1 = minimum field width
	// %- left align 
	
	printf("Item 1: $%.2f\n",item1);
	printf("Item 2: $%.2f\n",item2);
	printf("Item 3: $%.2f\n",item3);
}
