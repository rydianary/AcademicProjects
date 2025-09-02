//Reverse a linked list 
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data; 
	struct Node* next; 
};

struct Node* head; 
void Print(){
	struct Node* temp = head; 
	printf("List is: ");
	while(temp!= NULL){
		printf(" %d", temp->data); 
		temp=temp->next;
	}
	printf("\n");
}
void Insert(int data, int n){
	struct Node* temp1=(struct Node*)malloc(sizeof(struct Node)); 
	temp1->data=data; 
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
void Delete(int n){
	struct Node* temp1=head;
	if(n==1){
		head=temp1->next; //head now points to 2nd node
		free(temp1);
		return;
	} 
	int i; 
	for(i=0;i<n-2;i++){
		temp1=temp1->next;
		//temp1 points to (n-1)th node
	}
	struct Node* temp2 = temp1->next; //nth Node 
	temp1->next = temp2->next; //(n+1)th Node 
	free(temp2); //delete temp2
} 
void Reverse(){
	struct Node *current, *prev, *next; 
	current=head; 
	prev=NULL;
	while(current !=NULL){
		next= current->next;
		current->next=prev; 
		prev=current; 
		current = next; 
	}
	head=prev; 
}
int main(){
	head=NULL; //empty list
	Insert(2,1);
	Insert(4,1);
	Insert(6,1);
	Insert(5,1); //list: 2,4,6,5
	Print(); 
	int n; 
//	printf("Enter a position\n");
//	scanf("%d",&n);
//	Delete(n);
//	Print();
	Reverse(); 
	Print();
}
