#include<iostream>
#include<stdio.h>
#include<stdlib.h>


using namespace std;

//binary search tree search, insert & deletion 
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode (int key){
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorderTraversal(struct node* head){
	if(head != NULL){
		inorderTraversal(head->left);
		std::cout<<head->data<<"->";
		inorderTraversal(head->right);
	}
}

int search(struct node* head, int key){
	if( head->data == key) return head->data;
	if(head->data > key){
		return search( head->left, key);
	}
	else{
		return search(head->right, key);
	}
}

struct node* insert(struct node* head, int key ){
	if(head == NULL) return (newNode(key));
	
	if(key < head->data){
		head->left = insert(head->left, key);
	}
	else{
		head->right = insert(head->right, key);
	}
	return head;	
}

struct node* minValueNode(struct node *head){
	struct node* current = head;
	while(current->left != NULL){
		current = current ->left;
	}
	return current;
}
struct node * deleteNode(struct node *head, int key){
	if(head == NULL) return head;
	if(key < head->data){
		head->left = deleteNode(head->left, key);
	}
	else if (key > head->data){
		head->right = deleteNode(head->right, key);
	}
	else{
		if(head->left == NULL){
			struct node* temp = head->right;
			free(head);
			return temp;
		}
		else if(head->right == NULL){
			struct node* temp = head->left;
			free(head);
			return temp;
		}
		struct node* temp = minValueNode(head->right);
		head->data = temp->data;
		head->right = deleteNode(head->right, temp->data);
	}
	return head;
}

int main(){
	struct node* root = NULL;
	root = insert(root,50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	
	inorderTraversal(root);
	std::cout<<endl;
	
	//std::cout<<"if element present returns element, else -1 "<<search(root, 20)<<endl;
	//std::cout<<"if element present returns element, else -1 "<<search(root, 19)<<endl;
	
	root = deleteNode(root, 20);
	inorderTraversal(root);
	std::cout<<endl;
	
	root = deleteNode(root, 30);
	inorderTraversal(root);
	std::cout<<endl;
	
	root = deleteNode(root, 50);
	inorderTraversal(root);
	std::cout<<endl;
	system("pause");
	
}
