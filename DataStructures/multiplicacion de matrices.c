/*Estructuras de datos - LIS 2032-1
Nombre Completo: Diana Laura Reyes Youshimatz
ID: 173391
Descripción breve del programa:
Calculadora de matrices
	-Inicio
	-Se ingresa la dimenson de la matriz 1
	-Se llena la matriz 1 
	-Se ingresa la dimenson de la matriz 2
	-Se verifica si pueden ser multiplicadas
	-Se llena la matriz 2 
	-Se imprimen matrices 1 y 2 
	-Se multiplican matrices 
	-Se imprime matriz resultante 
	-Fin*/
#include<stdio.h>
//PROGRAMA MULTIPLICACION DE MATRICES 

int main(){
    int i, j, c1, r1, r2, c2, k, sum=0, m1[10][10], m2[10][10], res[10][10];
	printf("Multiplicadora de matrices\n");
    printf("Ingresa el numero de renglones y columnas de la matriz 1: \n");
    scanf("%d%d", &r1, &c1);
	
	//llenado matriz 1
    printf("\nIngresa los %d elementos de la matrix 1: \n\n", r1*c1);
    for(i=0;i<r1;i++)  
        for(j=0;j<c1;j++)  
            scanf("%d", &m1[i][j]);

    printf("\nIngresa el numero de renglones y columnas de la matriz 2:\n");
    scanf("%d%d", &r2, &c2);
 
    if(c1!=r2) //checar si las matrices se pueden multiplicar
        printf("Las matrices ingresadas no pueden ser multiplicadas. Intenta otro orden \n\n");

    else{
    	
    	//llenado matriz 2
        printf("\nIngresa los %d elementos de la matriz 2: \n",r2*c2);

        for(i=0;i<r2;i++)   
            for(j=0;j<c2;j++)  
                scanf("%d", &m2[i][j]);

        // imprimir matriz 1
        printf("\nMatriz 1: \n");
        for(i=0;i<r1;i++) {
            for(j=0;j<c1;j++){
                printf("[%d]\t", m1[i][j]);
            }
            printf("\n");
        }

        // imprimir matriz 2
        printf("\nMatriz 2: \n");
        for(i=0;i<r2;i++){
            for(j=0; j<c2; j++) {
                printf("[%d]\t", m2[i][j]);}
            printf("\n");}
		//multiplicacion
        for(i=0;i<r1;i++) {
            for(j=0;j<c2;j++){
                for(k=0;k<r2;k++){
                    sum=sum+m1[i][k]*m2[k][j]; //multiplica cada renglon del elemento por su columna reciproca
                }
            res[i][j]=sum;    // asigna el resultado de la suma de las multiplicaciones 
            sum=0;  }
        }
        //imprimir matriz resultado
        printf("\n\n Resultado:\n");
        for(i=0;i<r1;i++) {
            for(j=0;j<c2;j++){
                printf("[%d]\t", res[i][j]);}
            printf("\n"); }
    }
    return 0;}
