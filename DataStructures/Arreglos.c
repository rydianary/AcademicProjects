#include <stdio.h>

int main(){
printf("\n Programa que obtiene los 100 primeros números enteros ");

   printf("\n y los almacena en un arreglo, también los imprime en pantalla \n\n ");
	int x, tabla[100];
	for(x=0; x<100; x++)
	{
		tabla[x]=x;
		}	 
	for(x=0;x<100; x++){
		printf("%d\n", tabla[x]);
	}
		

	return 0;
}
