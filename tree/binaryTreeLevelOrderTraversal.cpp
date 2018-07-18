#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newnode( int key){
	struct node *temp = (struct node* ) malloc(sizeof(struct node));
	temp->data =  key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(struct node* head){
	if(head == NULL) return;
	inorder(head->left);
	std::cout<<head->data<<"->";
	inorder(head->right);
}
int height(struct node* head){
	if(head == NULL) return 0;
	return 1 + max(height(head->left), height(head->right));
}


void printLevel(struct node* head, int level){
	if(head == NULL) return;
	if(level == 1){
		std::cout<<head->data <<"->";
	}
	else if( level > 1){
		printLevel(head->left, level-1);
		printLevel(head->right, level-1);
	}
}
void printLevelOrder(struct node* head){
	int h = height(head);
	for(int i = 1; i<=h; i++ ){
		printLevel(head, i);
	}
}

int main(){
	struct node* root = NULL;
	root= newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left =  newnode(4);
	root->left->right = newnode(5);
	inorder(root);
	std::cout<<endl;
	std::cout<<"height of the given tree is :" <<height(root)<<endl;
	
	printLevelOrder(root);
	system("pause");
}
