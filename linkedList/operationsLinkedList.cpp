#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

void printList(struct Node*trav){
	while(trav!= NULL){
		std::cout << trav->data <<"->";
		trav = trav -> next;
	}
	std::cout<<endl;
}
void append(struct Node** headD, int newdata){
	
	struct Node* newnode = (struct Node *) malloc(sizeof(struct Node));
	newnode -> data = newdata;
	newnode -> next = NULL;
	
	struct Node *last = *headD;
	if(*headD == NULL){
		*headD = newnode;
		return;
	}
	
	while(last -> next != NULL){
		last = last -> next;
	}	
	
	last -> next = newnode;
	return;
}
//insert element at position
void insertAfter(struct Node** headnode, int newdata, int pos ){
	struct Node* newnode = (struct Node* )malloc(sizeof(struct Node));
	newnode->data = newdata;
	newnode->next = NULL;
	
	struct Node* last = *headnode;
	if(pos == 0){
		newnode->next = last;
		*headnode = newnode;
	}
	else{
		struct Node* temp = *headnode;
		for (int i = 0; i< pos; i++){
			temp =  last;
			last = last->next;
		}
		temp -> next =  newnode;
		newnode -> next = last;
	}
}
//deletion of element
void deleteElem(struct Node** headnode, int key){
	struct Node* last = * headnode;
	struct Node* temp =  NULL;
	struct Node* prev =  last;
	if(last->data == key){
		temp = last;
		*headnode = temp->next;
	}
	while(last != NULL){
		if(last->data == key){
			prev->next = last ->next;
			temp = last;
			break;
		}
		prev = last;
		last =  last->next;
	}
	free(temp);
}
int main(){
	struct Node* head = NULL;
	append(&head, 6);
	append(&head, 10);
	append(&head, 16);
	append(&head, 12);
	append(&head, 7);
	printList(head);
	insertAfter(&head, 3, 3);
	printList(head);
	std::cout << "deletion"<<std::endl;
	deleteElem(&head, 7);
	printList(head);
	system("pause");
}
