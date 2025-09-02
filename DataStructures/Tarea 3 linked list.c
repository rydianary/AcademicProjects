/*Estructuras de datos - LIS 2032-1
Nombre Completo:
ID:
Descripción breve del programa:*/
#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data; 
	struct Node* next;
};
struct Node* head; 
void InsertFinal(){
	printf("Valor: ");int x; scanf("%d",&x);
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node)); 
	struct Node* ptr; ptr=head;
	temp->data=x; 
	temp->next=NULL; 
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=temp;
}
void InsertInicio(){
	printf("Valor: "); int x; scanf("%d",&x);
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node)); 
	temp->data=x; 
	temp->next=head; 
	head = temp; 
}
void InsertMiddle(){
	printf("  Posicion: "); int n; scanf("%d",&n);
	printf("  Valor: "); int x; scanf("%d",&x);
	struct Node* ptr= head; 
	struct Node* temp1=(struct Node*)malloc(sizeof(struct Node)); 
	temp1->data=x; 
	temp1->next=NULL; 
	if(n==1){
		temp1->next=head;
		head = temp1; 
		return;	
	} 
	struct Node* temp2 = head;
	int i; 
	for(i=0; i<n-2; i++){
		temp2 = temp2 -> next;
	}
	temp1->next=temp2->next; 
	temp2->next=temp1;
	

}
void Print(){
	struct Node* temp = head; 
	printf("Lista: ");
	while(temp!= NULL){
		printf(" %d", temp->data); 
		temp=temp->next;
	}
	printf("\n");
}
void DeleteMiddle(){
	printf("Posicion del dato a eliminar: ");
	int n; scanf("%d", n);
	struct Node* temp1=head;
	struct Node* temp2 = temp1->next; //nth Node 
	if(head=NULL) {
		printf("Lista vacia\n");
		return;
	}
	if(n==1){
		head=temp1->next; //head now points to 2nd node
		free(temp1);
		return;
	} 
	int i; 
	for(i=0;i<n-2;i++){
		temp2=temp1;
		temp1=temp1->next;
		//temp1 points to (n-1)th node
	}
	temp2->next = temp1->next; //(n+1)th Node 
	free(temp1); //delete temp2
	temp2=NULL;
}
void DeleteInicio(){
	if(head == NULL){
        printf("Lista vacia");
        return;
    }
    if(head->next==NULL){
    	free(head);
    	return; 
	}
	struct Node* temp1=head;
	head=temp1->next; 
	free(temp1);  
}
void DeleteFinal(){
	if(head == NULL){
        printf("Lista vacia");
        return;
    }
    if(head->next==NULL){
    	free(head);
    	return; 
	}
	struct Node* temp1=head; struct Node* temp2=head;
	while(temp1->next!=NULL){
		temp2=temp1;
		temp1=temp1->next;
	}
	temp2->next=NULL;
	free(temp1);
	temp1=NULL;
}
int main(){
	head=NULL; 
	printf("\n LISTAS ENLAZADAS SIMPLES");
	printf("\n\t\t MENU");
	printf(" \n 1 : Insertar un nodo al inicio");
	printf(" \n 2 : Insertar un nodo al final");
	printf(" \n 3 : Insertar un nodo intermedio");
	printf(" \n 4 : Eliminar un nodo al inicio");
	printf(" \n 5 : Eliminar un nodo intermedio");
	printf(" \n 6 : Eliminar un nodo al final");
	printf(" \n 7 : Imprimir LISTA");
	printf(" \n 8 : SALIR");
int choice;
do{
	printf(" \n Introduzca la opcion: ");
	scanf("%d", &choice);
	switch(choice){
	case 1:{ // Case 1 Agrega un nodo al inicio
		InsertInicio();
		break;}
	case 2:{ // Case 2 Agrega un nodo al final
		InsertFinal();
		break;}
	case 3:{ // Case 3 Agrega un nodo en posicion especifica
		InsertMiddle();
		break;}
	case 4:{
		DeleteInicio(); // Case 4 Elimina un nodo al inicio
		break;
	}
	case 5:{
		DeleteMiddle(); // Case 5 Elimina un nodo intermedio
		break;
	}
	case 6:{
		DeleteFinal(); // Case 6 Elimina un nodo al final
		break;
	}
	case 7:{
		Print(); // Case 7 Imprime la lista
		break;
	}
	case 8:{ // Salir
		exit(0);
		break;
	}
	default:{
		printf(" This option doesn't exist'...\n");
		break;
	}
	}//end switch
 }while(choice!= 0);
} // end main
