#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define max_array 100

// Define la estructura de una pila
typedef struct{
	int tope; //El �ltimo elemento que entra
	int vector[max_array];
}stack;

// Funci�n que crea una pila
void CrearPila(stack *Pila){
	Pila->tope = -1;
}

//informacion del auto
typedef struct{
	char nombre[20], placas[10]; int modelo[5];
	char getnombre(void){
		scanf("%c",&nombre);
	}
	char getplacas(void){
		scanf("%c",&placas);
	}
	int getmodelo(void){
		scanf("%d",&modelo);
	}
}autoinfo;

// Funci�n que nos dice si est� vac�a una pila
int isEmpty(stack *Pila, int tag){
	if(Pila->tope == -1){
	printf("La pila est� vac�a \n");
	return true;
 }
 else{
	if(tag==1){
	printf("La pila no est� vac�a \n");
 }
 return false;
 }
}

// Funci�n que nos dice si est� llena una pila
int isFull(stack *Pila, int tag){
	if(Pila->tope == max_array-1){
	printf("La pila est� llena \n");
	return true;
 }
 else{
 if(tag==1){
	printf("La pila no est� llena \n");
 }

 return false;
 }
}
// Funci�n que agrega un elemento a una pila, solamente si no est� llena
void Push(stack *Pila, int tag){
 if(!isFull(Pila, tag)){
	Pila->tope++;
	Pila->vector[Pila->tope]= autoinfo;
	printf("Se ha colocado el elemento %d en la pila\n",Pila->vector[Pila->tope]);
	printf("La pila ahora tiene %d elementos \n", Pila->tope+1);
 }
else{
	printf("La pila est� llena \n");
 }
}

// Funci�n que elimina un elemento de una pila, solamente si no est� vac�a
void Pop(stack *Pila, int tag){
	if(!isEmpty(Pila, tag)){
		int tmp= Pila->tope;
		Pila->tope--;
		printf("Se extrajo el elemento %d que estaba en el �ndice %d\n",Pila->vector[tmp],tmp);
		printf("La pila ahora tiene %d elementos \n",Pila->tope+1);
	}
	else{
		printf("La pila estaba vac�a \n");
	}
}
// Funci�n que imprime los elementos de una pila, solamente si no est� vac�a
void ImprimirPila(stack *Pila, int tag){
	int i;
	if(!isEmpty(Pila, tag)){
		int tmp= Pila->tope;
		printf("La pila tiene %d elementos.\n",tmp+1);
		for(i=0;i<=tmp;i++){
			printf("El elemento %d se encuentra en el �ndice %d de la pila\n",Pila->vector[i],i);}
 }
 else{
printf("La pila estaba vac�a \n");}
}


int main() {
	int op,dato,tag;
	stack Pila;
	CrearPila(&Pila);
	
	printf("\nPrograma que realiza las operaciones b�sicas en una PILA \n\n");
	do{
		do{
			printf("\nElige una opci�n a realizar: \n");
			printf("1. Agregar elemento a la pila (Push).\n");
			printf("2. Eliminar elemento de la pila (Pop).\n");
			printf("3. Imprimir los elementos de la pila.\n");
			printf("4. Consultar si la pila est� vac�a (isEmpty).\n");
			printf("5. Consultar si la pila est� llena (isFull).\n");
			printf("6. SALIR...\n");
			printf("Opci�n:... ");
			scanf("%i",&op);
			}while(op < 1 || op > 6);
			
			
			switch(op){
			case 1:{
				tag=0;
				printf("\n");
				printf("Introduce el nombre, placas y modelo del auto: ");
				autoinfo autox;
				autox.getnombre();
				Push(&Pila, autox,tag);
				break;
			}
			case 2:{
				tag=0;
				
				printf("\n");
				Pop(&Pila,tag);
				break;
			}
			case 3:{
				tag=0;
				printf("\n");
				ImprimirPila(&Pila,tag);
				break;
			}
			 case 4:{
				tag=1;
				printf("\n");
				isEmpty(&Pila,tag);
				break;
			}
			 case 5:{
				tag=1;
				printf("\n");
				isFull(&Pila,tag);
				break;
			}
				case 6:{
				exit(0);
				break;
			}
			}
		}while(op!=6);
	
	 return 0;
}
