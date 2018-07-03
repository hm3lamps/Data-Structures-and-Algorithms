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
		std::cout<< headnode->data <<"->";
		headnode = headnode->next;
	}
	std::cout<<endl;
}
void push(struct node** headnode, int newdata){
	struct node* newnode =(struct node*) malloc(sizeof(struct node));
	newnode -> data = newdata;
	newnode -> next =  *headnode;
	*headnode = newnode;
}

bool detectLoop(struct node* list){
	struct node *slowp, * fastp = list; 
	while(slowp && fastp && fastp->next){
		slowp =  slowp ->next;
		fastp = fastp ->next->next;
		if(slowp == fastp){
			return true;
		}
	}
	return false;
}
int main(){
	struct node* head = NULL;
	push(&head, 3);
	push(&head, 10);
	push(&head, 7);
	push(&head, 12);
	head ->next->next->next->next = head;
	//printList(head);
	std::cout << "Detecting Loop 	1 for yes, 0 for no"<<std::endl<<detectLoop(head);
	std::cout<< endl;
	system("pause");
}
