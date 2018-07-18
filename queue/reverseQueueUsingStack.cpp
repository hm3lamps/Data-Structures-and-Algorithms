#include<iostream>
#include<stack>
#include<queue>

using namespace std;

void printQueue(queue<int>& q){
	while(!q.empty()){
		std::cout<<q.front()<<" ";
		q.pop();
	}
	std::cout<<endl;
}

void reverseQueue(queue<int>&q ){
	stack<int> s;
	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
}
int main(){
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	q.push(70);
	reverseQueue(q);
	printQueue(q);
	
	system("pause");
}
