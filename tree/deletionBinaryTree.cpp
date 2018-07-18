#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

void inorder( struct node* head){
	if(head == NULL) return;
	inorder(head->left);
	std::cout<<head->data<< "->";
	inorder(head->right);
}

struct node* newnode(int key){
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
}
void deleteDeepest(struct node* first, struct node* dnode){
	
	queue<struct node* > q;
	q.push(first);
	struct node* temp;
	while(!q.empty()){
		temp = q.front();
        q.pop();
		if(temp->right){
			if(temp->right == dnode){
				temp->right = NULL;
				delete(dnode);
				return;
			}
			else{
				q.push(temp->right);
			}
		}
		if(temp->left){
			if(temp->left ==  dnode){
				temp->left =NULL;
				free(temp);
				return;
			}
			else{
				q.push(temp->left);
			}

		}	
	}
}
void deletion(struct node* head, int key){
	queue<struct node*> q;
	q.push(head);
	struct node *temp ;
	struct node *keyDelNode = NULL;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		
		if(temp->data == key) keyDelNode = temp;
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
	int x = temp->data;
	deleteDeepest(head, temp);
	keyDelNode->data =  x;
}
int main(){
	struct node* root = newnode(10);	
	root->left = newnode(11);
    root->left->left = newnode(7);
    root->left->right = newnode(12);
    root->right = newnode(9);
    root->right->left = newnode(15);
    root->right->right = newnode(8);
 
    cout << "Inorder traversal before deletion : ";
    inorder(root);
    std::cout<<endl;
    
    int deleteNum = 11;
    deletion(root, 11);
    inorder(root);
    std::cout<<endl;
    system("pause");
 
}
