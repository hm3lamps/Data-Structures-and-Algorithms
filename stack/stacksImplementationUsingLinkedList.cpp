#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
	int data;
	struct Node* next;
};

void printList( struct Node* trav){
	while (trav!=NULL){
		std::cout<<trav ->data <<"->";
		trav = trav ->next;
	}
	std::cout<<endl;
}
int isEmpty(struct Node* root){
	return !root;
}
void push(struct Node** headnode, int data){
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode -> data =  data;
	newnode	-> next = *headnode;
	*headnode = newnode;
	//std::cout<<"Pushed Element onto Stack:";
}

int pop(struct Node** rootNode){
	if(isEmpty(*rootNode)){
		return -1;
	}
	struct Node* temp = *rootNode;
	*rootNode = (*rootNode) -> next;
	int data = temp->data;
	free(temp);
	return data;
}
//stack implementation using LinkedList
int main(){
	struct Node* head = NULL;
	push(&head, 10);
	push(&head, 12);
	push(&head, 14);
	printList(head);
	std::cout<<"item popped:"<<pop(&head)<<endl;
	std::cout<<"item popped:"<<pop(&head)<<endl;
	std::cout<<"item popped:"<<pop(&head)<<endl;
	std::cout<<"item popped:"<<pop(&head)<<endl;
	system("pause");
	
}

