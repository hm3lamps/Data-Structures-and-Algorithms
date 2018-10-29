#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* next;
};

void printList(struct node* headnode){
	while(headnode != NULL){
		std::cout << headnode->data << "->";
		headnode = headnode->next;
	}
	std::cout << endl;
}

void push (struct node** head, int data){
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = *head;
	*head = newnode;
}

void deleteNode(struct node** head, int key){
}
int main(){
	struct node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	
	printList(head);
	system("pause");
	return 1;
}

