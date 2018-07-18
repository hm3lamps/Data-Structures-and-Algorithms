#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <queue>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void inorder(struct node *head){
	if(head == NULL)return;
	inorder(head->left);
	std::cout<<head->data<<"->";
	inorder(head->right);
}
struct node * newnode(int key){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp; 
}

void insert(struct node *head, int key){
	queue <struct node*> q;
	q.push(head);
	while(!q.empty()){
		struct node* temp = q.front();
		q.pop();
		if(!temp->left){
			temp->left = newnode(key);
			break;
		}
		else{
			q.push(temp->left);
		}
		if(!temp->right){
			temp->right = newnode(key);
			break;
		}else{
			q.push(temp->right);
		}
	}
}
int main(){
	struct node *root = newnode(10);
	root->left = newnode(11);
	root->left->left = newnode(7);
	root->right = newnode(9);
	root->right->left = newnode(15);
	root->right->right = newnode(8);
	
	std::cout<<"inorder traversal : "<<endl;
	inorder(root);
	std::cout<<endl;
	
	insert(root, 12);
	inorder(root);
	std::cout<<endl;
	
	system("pause");
}

