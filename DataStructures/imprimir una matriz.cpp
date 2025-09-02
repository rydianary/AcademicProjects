//PROGRAMA QUE IMPRIME LOS VALORES DE UNA MATRIZ 
#include<stdio.h>
int main(){
	int a[5][2]={{0,0},{1,2},{2,4},{3,6},{4,8}};
	int i, j; 
	printf("\n Programa que imprime una matriz \n\n"); 
	for(i=0;i<5; i++) //fija un renglon 
	{
		for(j=0; j<2; j++){ //recorre las columnas
			
			printf("a[%d][%d]=%d\n", i,j, a[i][j]); 
		}
	}
	printf("progrma finalizado \n ");
	return 0; 
}

