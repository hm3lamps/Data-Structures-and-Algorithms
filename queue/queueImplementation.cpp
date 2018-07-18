#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Queue {
	int rear, front , size;
	unsigned capacity;
	int * array;	
};

struct Queue* createQueue(unsigned capacity){
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue*));
	queue -> capacity = capacity;
	queue -> front = queue ->size = 0 ;
	queue -> rear = -1;
	queue -> array = (int*) malloc(capacity *sizeof(int));
	return queue;
}

int isFull(struct Queue* queue){
	return (queue -> size == queue ->capacity);
}

int isEmpty(struct Queue* queue){
	return (queue ->size == 0);
}
void addToQueue(struct Queue* queue, int item ){
	if( isFull(queue)) {
		std::cout<<"queue full"<<endl;
		return;
	}
	queue->rear = (queue -> rear) + 1;
	queue->array[queue->rear] = item;
	queue->size = queue->size+1;
	std::cout<<"Element added to the queue: "<<item<<endl;
	std::cout<<"rear value"<<queue->rear<<endl;
}
int delFromQueue(struct Queue* queue){
	if(isEmpty(queue)) return -100;
	int item = queue ->array[queue->front];
	queue->front = (queue ->front) + 1;
	queue->size = queue->size-1;
	return item;
}

int front(struct Queue* queue){
	if(isEmpty(queue)) return -100;
	return queue->array[queue->front];
}
int rear(struct Queue* queue){
	if(isEmpty(queue)) return -100;
	return queue->array[queue->rear];
}
int main(){
	struct Queue* queue = createQueue(3);
	addToQueue(queue, 10);
	addToQueue(queue, 20);
	addToQueue(queue, 30);
	addToQueue(queue, 40);
	
	std::cout<<"deleting element from queue: "<< delFromQueue(queue) <<endl;
	//std::cout<<"deleting element from queue: "<< delFromQueue(queue) <<endl;
	//std::cout<<"deleting element from queue: "<< delFromQueue(queue) <<endl;
	std::cout<<"Front element of the queue:" <<front(queue)<<endl;
	std::cout<<"Rear element of the queue:" << rear(queue)<<endl;
	
	system("pause");
}












