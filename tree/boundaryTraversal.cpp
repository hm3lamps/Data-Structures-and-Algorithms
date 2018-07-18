#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int key){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(struct node* head){
	if(head == NULL) return;
	inorder(head->left);
	std::cout<<	head->data <<"->";
	inorder(head->right);
}

void printLeaves(struct node* head){
	if(head){
		printLeaves(head->left);
		
		if(!(head->left) && !(head->right)){
			std::cout<<head->data<<"->";
		}
		printLeaves(head->right);
		
	}
	
}
void printBoundaryLeft( struct node* head){
	if(head){
		if(head->left){
			std::cout<<head->data <<"->";
			printBoundaryLeft(head->left);
		}
		else if(head->right){
			std::cout<<head->data<<"->";
			printBoundaryLeft(head->right);
		}
	}
}

void printBoundaryRight(struct node* head){
	if(head){
		if(head->right){
			printBoundaryRight(head->right);
			std::cout<<head->data<<"->";
		}
		else if(head->left){
			printBoundaryRight(head->left);
			std::cout<<head->data<<"->";
		}
	}
}
void printBoundary(struct node* head){
	if(head){
		std::cout<<head->data<<"->";
		printBoundaryLeft(head->left);
		printLeaves(head->left);
		printLeaves(head->right);
		printBoundaryRight(head->right);	
	}
}

int main(){
	struct node *root = newNode(20);
	root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
	
	inorder(root);
	std::cout<<endl;
	printBoundary(root);
	system("pause");
}
