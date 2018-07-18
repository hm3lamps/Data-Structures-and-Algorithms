#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};

void inorder(struct node *head){
	if(head == NULL) return;
	inorder(head->left);
	std::cout<<head->data<<"->";
	inorder(head->right);
}
void postorder(struct node *head){
	if(head == NULL) return;
	postorder(head->left);
	postorder(head->right);
	std::cout<<head->data <<"->";
}
void preorder(struct node *head){
	if(head == NULL) return;
	std::cout<<head->data<<"->";
	preorder(head->left);
	preorder(head->right);
}

struct node* newnode(int key){
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = key;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}



int main(){
	struct node* root = NULL;
	root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	
	std::cout<<"pre order traversal";
	preorder(root);
	std::cout<<endl;
	
	std::cout<<"inorder traversal";
	inorder(root);
	std::cout<<endl;
	
	std::cout<"post order traversal";
	postorder(root);
	std::cout<<endl;
	system("pause");
}








