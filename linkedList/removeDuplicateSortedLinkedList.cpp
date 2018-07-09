#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};
void printList(struct Node* trav){
	while(trav != NULL){
		std::cout<< trav->data <<"->";
		trav = trav->next;
	}
	std::cout<<endl;
}

void append(struct Node** headNode , int data){
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode -> data =  data;
	newnode -> next =  NULL;
	
	struct Node* last = * headNode;
	if(*headNode == NULL){
		*headNode = newnode;
		return;
	}
	
	while(last->next != NULL){
		last = last->next;
	}
	last -> next =  newnode;
	return;
}

void removeDuplicate(struct Node** headNode){
	
	struct Node* last = * headNode;
	struct Node* nexttemp;
	while(last->next != NULL){
		
		if(last->data == last -> next ->data){
			nexttemp = last->next->next;
			free(last->next);
			last->next =nexttemp;
		}
		else{
			last =  last->next;
		}
	}
	
}
int main(){
	struct Node* head = NULL;
	append(&head, 11);
	append(&head, 11);
	append(&head, 11);
	append(&head, 13);
	append(&head, 13);
	append(&head, 20);
	printList(head);
	removeDuplicate(&head);
	printList(head);
	system("pause");
}

