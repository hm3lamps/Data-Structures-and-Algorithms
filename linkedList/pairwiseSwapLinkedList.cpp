#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
	int data;
	struct Node* next;
};

void printList(struct Node* trav){
	while(trav!= NULL){
		std::cout<< trav ->data<<"->";
		trav = trav -> next;
	}
	std::cout<<endl;
}

void append(struct Node** headnode, int newdata){
	struct Node* newnode =  (struct Node*)malloc(sizeof(struct Node));
	newnode-> data = newdata;
	newnode-> next = *headnode;
	*headnode =  newnode;
	return;
}

void pairwiseSwap(struct Node* headnode){
	struct Node* temp  =  headnode;
	while(temp!= NULL && temp->next!=NULL){
		int a = temp->data;
		int b = temp->next->data;
		temp->data = b;
		temp->next->data = a;
		temp = temp->next->next;
	}
}

void pairwiseSwapPointer(struct Node** headnode){
	struct Node* temp2 = *headnode;
	struct Node* prev =  *headnode;
	int count = 0;
	while(temp2!=NULL && temp2->next!= NULL){
		struct Node* node1 = temp2->next;
		struct Node* node2 = temp2->next->next;
		temp2->next =  node2;
		node1->next = temp2;
		if(count == 0){
			*headnode = node1;
		}	
		else{
			prev->next = node1;
		}
	 count++;
	 prev = temp2;
	 temp2 = node2;
	}
}
int main(){
	struct Node* head = NULL;
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	append(&head, 5);
	printList(head);
	pairwiseSwap(head);
	printList(head);
	pairwiseSwapPointer(&head);
	printList(head);
	system("pause");
}
