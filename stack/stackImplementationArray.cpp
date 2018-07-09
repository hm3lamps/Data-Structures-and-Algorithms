#include<iostream>
using namespace std;

class Stack{
		int top;
	public:
		int arr[1000];
		Stack(){
			top = -1;
		}
		bool push(int data);
		int pop();
		bool isEmpty();
};
bool Stack::push(int data){
	if(top>=1000-1){
		std::cout<<"stack overflow";
		return false;
	}
	else{
		top = top+1;
		arr[top] = data;
		return true;
	}
}
int Stack::pop(){
	if(top<0){
		std::cout<<"stack has no more elements";
		return 0;
	}
	else{
		int x = arr[top];
		top = top-1;
		return x;
	}
}
bool Stack::isEmpty(){
	if(top<0){
		return true;
	}
}

int main(){
	struct Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	
	std::cout<<"The top element is :"<<s.pop()<<endl;
	std::cout<<"The top element is :"<<s.pop()<<endl;
	std::cout<<"The top element is :"<<s.pop()<<endl;
	std::cout<<"The top element is :"<<s.pop()<<endl;
	
	system("pause");
}
