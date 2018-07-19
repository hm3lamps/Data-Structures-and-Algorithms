#include<iostream>
#include<stdio.h>

using namespace std;

void swap(int *p1, int *p2){
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void selectionSort(int arr[], int n){
	int i, j, minIndex;
	for( i = 0; i < n-1; i++){
		minIndex = i;
		for(j = i+1; j < n; j++){
			if(arr[j] < arr[minIndex])
				 minIndex = j;
		}
		swap(&arr[minIndex], &arr[i]);
	}
		
}

void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		std::cout << arr[i] <<"->";
	}
	std::cout<<endl;
}

int main(){
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/ sizeof(arr[0]);
	
	printArray(arr, n);
	selectionSort(arr, n);
	printArray(arr, n);
	system("pause");	
}
