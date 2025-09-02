#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define max_array 100

typedef struct{
	char nombre, placas; int modelo; 
}info;
// Define la estructura de una pila
typedef struct{
 int tope; //El último elemento que entra
 int vector[max_array];
}stack;

// Función que crea una pila
void CrearPila(stack *Pila){
 Pila->tope = -1;
}

