#include<stdio.h>
int main(){
	int x, i=0, tabla[100];
	for(x=0;x<100;x++){
		if(x%2==1){
			tabla[i]=x; 
			i++; 
		}
	}
	for(x=0; x<i; x++){
		printf("%d\n",tabla[x]);
	}
}
