#include<stdio.h>

void print(char* C){
	C[0]='A'; 
	while(*C !='\0'){
		printf("%c", *C);
		C++;
	}
	printf("\n");
}
int main(){
	//char C[20]="Hello"; //string gets stored in the space for array
	char *C="Hello"; //string gets stored as a compile time constant
	print(C);
}
