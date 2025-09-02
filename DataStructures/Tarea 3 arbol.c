/*Estructuras de datos - LIS 2032-1
Nombre Completo: Diana Laura Reyes Youshimatz
ID: 173391
Descripción breve del programa: Implementacion de un arbol
binario, donde se utiliza root para organizar correctamente los datos
ademas de usar structuras que permitan regresar este valor continuamente
para realizar casi todas las operaciones. 
las funciones son: 
-insertar un nodo (se agrega la funcion de crear un nodo para insertar)
• Eliminar un nodo
• Buscar un valor/nodo (existe o no)
• Encontrar el valor más pequeño del árbol
• Encontrar el valor más grande el árbol
• Determinar la altura del árbol
• Imprimir el árbol en Pre-orden
• Imprimir el árbol en In-orden
• Imprimir el árbol en Post-orden
• Eliminar todo el árbol
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
struct BstNode{
	int data; 
	struct BstNode* left;
	struct BstNode* right; 
};
struct BstNode* CreateNode(int data){
	struct BstNode* newNode =(struct BstNode*)malloc(sizeof(struct BstNode));
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}
struct BstNode* Insert(struct BstNode* root, int data){
	if(root==NULL){
		root=CreateNode(data);
	}
	else if(data<=root->data){
		root->left=Insert(root->left,data); 
	}
	else{
		root->right=Insert(root->right, data);
	}
	return root; 
}
void Preorden(struct BstNode *root) {
	if(root == NULL) return;

	printf("%d ",root->data); 
	Preorden(root->left);     
	Preorden(root->right);    
}

void Inorden(struct BstNode *root) {
	if(root == NULL) return;

	Inorden(root->left);      
	printf("%d ",root->data);  
	Inorden(root->right);      
}
void Postorden(struct BstNode *root) {
	if(root == NULL) return;

	Postorden(root->left);    
	Postorden(root->right);   
	printf("%d ",root->data); 
}

bool Search(struct BstNode* root, int data){
	if(root==NULL) return false; 
	else if(root->data==data) return true; 
	else if(data<=root->data) return Search(root->left, data);
	else return Search(root->right, data); 
}
int FindMin(struct BstNode* root){
	if(root==NULL){
		printf("Arbol vacio\n");
		return -1;
	}
	while(root->left!=NULL){
		root=root->left;
	}
	return root->data; 
}
int FindMax(struct BstNode* root){
	if(root==NULL){
		printf("Arbol vacio\n");
		return -1;
	}
	while(root->right!=NULL){
		root=root->right;
	}
	return root->data; 
}
struct BstNode* Min(struct BstNode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
struct BstNode* Delete(struct BstNode *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);	
	else {
		// no hijos
		if(root->left == NULL && root->right == NULL) { 
			free(root);
			root = NULL;
		}
		//1 hijo
		else if(root->left == NULL) {
			struct BstNode *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL) {
			struct BstNode *temp = root;
			root = root->left;
			free(temp);
		}
		// 2 hijos
		else { 
			struct BstNode *temp = Min(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
int FindHeight(struct BstNode *root){
	if(root==NULL){
		return -1;
		return max(FindHeight(root->left), FindHeight(root->right))+1;
	}
}
void deleteTree(struct BstNode* root){
	if(root==NULL) return; 
	deleteTree(root->left);
	deleteTree(root->right);
	printf("\nBorrando nodo: %d", root->data);
	free(root);
}
int main(){
	struct BstNode* root=NULL; 
	root= Insert(root,15); //insertar
	root= Insert(root,10);
	root= Insert(root,20);
	root= Insert(root,25);
	root= Delete(root,25); //eliminar un nodo
	
	//buscar 
	printf("Ingresa un numero a buscar: "); 
	int num; scanf("%d",&num); 
	if(Search(root, num)==true){
		printf("Numero encontrado!\n"); 
	}
	else{
		printf("Numero NO encontrado\n"); 
	}
	root = Delete(root,25);
	//valor min 
	printf("valor minimo: "); 
	FindMin(root); 
	printf("\n");
	//valor max
	printf("valor maximo: "); 
	FindMin(root); 
	printf("\n");
	
	//imprimir preorden
	printf("Inorden: ");
	Preorden(root);
	printf("\n");
	//imprimir inorden
	printf("Inorden: ");
	Inorden(root);
	printf("\n");
	//imprimir postorden
	printf("Postorden: ");
	Postorden(root);
	printf("\n");
	
		//altura
	printf("Altura: ");
	FindHeight(root);
	printf("\n");
	
	//borrar arbol
	printf("Borrar arbol");
	deleteTree(root); 
    root = NULL;
    printf("\n Arbol borrado");


}
