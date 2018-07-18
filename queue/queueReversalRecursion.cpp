#include<iostream>
#include<queue>

using namespace std;

void printList(queue<int> q){
	while(!q.empty()){
		std::cout<<q.front()<<" ";
		q.pop();
	}
	std::cout<<endl;
}
//pass queue address	
void reverseQueue(queue<int> &q){
	if(q.empty()) return;
	int data = q.front();
	q.pop();
	reverseQueue(q);
	q.push(data);	
}
int main(){
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	
	reverseQueue(q);
	printList(q);
	
	system("pause");
}
