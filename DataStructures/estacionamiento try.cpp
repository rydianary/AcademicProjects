#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define true 1
#define false 0
#define max_array 50

//Define la estructura de una pila
typedef struct{
    int tope;//El ultimo elemento que entra en una pila
    int modelo[10];
    char nombre[30];
    char placas[10];

}stack;

//Funcion que crea una pila
void crearPila(stack *pila){
    pila->tope= -1;//cuando el tope sea igual a -1, la pila esta vacia
}

//pila vacia
int isEmpty(stack *pila, int tag){
    if(pila->tope==-1){
        printf("La pila esta vacia\n");
        return true;}
    else{
        if(tag==1){
            printf("La pila no esta vacia \n");
        }
        return false;
    }
}
//Funcion que nos dice si esta llena la pila
int isFull(stack *pila,int tag){
    if(pila->tope==max_array-1){
        printf("el estacionamiento esta lleno\n");
        return true;
    }
    else{
        if(tag==1){
            printf("el estacionamiento aun tiene lugares\n");
        }
        return false;
    }
}

//funcion que agrega un elemento a una pila
void push(stack *pila,int n,char m,char p,int tag){
    if(!isFull(pila,tag)){
        pila->tope++;
        pila->modelo[pila->tope]=n;
        pila->nombre[pila->tope]=m;
        pila->placas[pila->tope]=p;
        printf("El auto %d ya esta registrado en el estacionamiento\n",pila->modelo[pila->tope]);
        printf("El estacionamiento ahora tiene %d elementos \n",pila->tope+1);
    }
    else{
        printf("El estacionamiento esta lleno \n");
    }
}

//funcion que imprime los elementos de una pila, solamente si no esta vacia
void imprimirPila(stack *pila, int tag)
{
    int i;
     if(!isEmpty(pila,tag)){

        int tmp= pila->tope--;
        for(i=0;i<=tmp;i++){
        printf("Modelo: %d \n",pila->modelo[i]);
        printf("Auto: %c \n",pila->nombre[i]);
        printf("Placas %c \n",pila->placas[i]);
		}

    }

    else{
        printf("No hay autos en el estacionamiento \n");
    }


}
void Printautos(stack *pila)
{
    printf("Actualmente hay %d autos en el estacionamiento \n",pila->tope+1);
}

void printa1(stack *pila, int tag)
{
    int i;

        printf("Modelo: %d \n",pila->modelo[0]);
        printf("Auto: %c \n",pila->nombre[0]);
        printf("Placas %c \n",pila->placas[0]);
		

}

int main(){
    int op,dato,tag;
    char placas;
    char autos;
    stack pila;
    crearPila(&pila);//se envia como parametro la direccion de memoria de pila


    printf("\nPrograma que realiza las operaciones basicas en una PILA\n\n");
        do{
    do{
            printf("\nElige una opcion a realizar: \n");
            printf("1. Agregar un auto a la pila (Push).\n");
            printf("2. Imprimir la cantidad de autos que existen en el estacionamiento.\n");
            printf("3. Imprimir primer auto\n");
            printf("3. Imprimir lista de autos\n");
            printf("6. SALIR...\n");
            printf("Opcion: ");
            scanf("%i",&op);
    }while(op < 1 || op > 6);

    switch(op)
    {
    case 1:{
        tag=0;
        printf("\n");
        printf("Introduce el modelo: ");
        scanf("%d",&dato);
        printf("Introduce las placas: ");
        scanf(" %c",&placas);
        printf("Introduce el nombre del auto: ");
        scanf(" %c",&autos);
        push(&pila,dato,placas,autos,tag);
        break;
    }

    case 2:{
        tag=0;
        printf("\n");
        imprimirPila(&pila,tag);
        break;
    }
    case 4:{
        tag=1;
        printf("\n");
        Printautos(&pila);
        break;
    }
    case 3:{
        tag=1;
        printf("\n");
        printa1(&pila,tag);
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
