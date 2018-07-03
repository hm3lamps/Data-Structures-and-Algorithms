#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node {
	int data;
	struct Node * next;
};

void printList(struct Node* headnode){
	while(headnode!= NULL){
		std::cout<< headnode->data<<"->";
		headnode = headnode->next;
	}
	std::cout<<endl;
}

int getLength(struct Node* headnode){
	int count = 0;
	while(headnode!= NULL){
		count++;
		headnode =headnode -> next;
	}
	return count;
}
void append(struct Node** headnode, int newdata){
	struct Node * newnode = (struct Node* )malloc(sizeof(struct Node));
	newnode-> data = newdata;
	newnode -> next = NULL;
	
	struct Node* last = *headnode;
	if(last == NULL){
		*headnode = newnode;
		return;
	}
	while(last ->next !=NULL){
		last = last->next;
	}
	last->next = newnode;
	return;	
}

int main(){
	struct Node* head = NULL;
	append(&head, 2);
	append(&head, 5);
	append(&head, 9);
	append(&head, 10);
	printList(head);
	std::cout<< " length is :" <<getLength(head);
	std::cout<<endl;
	system("pause");
}
