//Linked list: Inserting a node at beginning 
#include<stdlib.h>
#include<stdio.h>
struct Node{
	int data; 
	struct Node* next;
};
struct Node* head; 
void Insert(int data, int n){
	struct Node* temp1=(struct Node*)malloc(sizeof(struct Node)); 
	temp1->data=data; 
	temp1->next=NULL; 
	if(n==1){
		head = temp1; 
		head = temp1; 
		return;	
	} 
	Node* temp2 = head;
	int i; 
	for(i=0; i<n-2; i++){
		temp2 = temp2 -> next;
	}
	temp1->next=temp2->next; 
	temp2->next=temp1;
	
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
	Insert(2,1); //2
	Insert(3,2); // 2,3
	Insert(4,1); //4,2,3
	Insert(5,2); //4,5,2,3
	Print(); 
		
	}
