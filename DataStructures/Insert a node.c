//Linked list: Inserting a node at beginning 
#include<stdlib.h>
#include<stdio.h>
struct Node{
	int data; 
	struct Node* next;
};
struct Node* head; 
void Insert(int x){
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node)); 
	temp->data=x; 
	temp->next=head; 
	head = temp; 
}
void Print(){
	struct Node* temp = head; 
	printf("List is: ");
	while(temp!= NULL){
		printf(" %d", temp->data); 
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	head = NULL; // empty list
	printf("Hoy many numbers?\n");
	int n, i, x; 
	scanf("%d",&n); 
	for(i=0; i<n;  i++){
		printf("Enter de number\n"); 
		scanf("%d", &x);
		Insert(x);
		Print(); 
		
	}
}
