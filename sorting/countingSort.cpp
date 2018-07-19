#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
#define RANGE 255

void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		std::cout << arr[i] <<"->" ;
	}
	std::cout << endl;
}

void countingSort(int arr[], int n){
	int output[n];
	
	int count[RANGE+1], i;
	memset(count, 0 , sizeof(count));
	
	for( i = 0; i < n; i++){
		count[arr[i]] = count[arr[i]] + 1;
	}
	for( i = 1; i <= RANGE; i++){
		count[i] = count[i] + count[i-1];
	}
	
	for( i = 0; i < n; i++){
		output[count[arr[i]]-1] = arr[i];
		count[arr[i]] = count[arr[i]] - 1;
	}
	
	for( i = 0; i < n ;i++){
		arr[i] = output[i];
	}
}

int main(){
	int arr[] = {2, 34, 54, 2, 3};
	int n = sizeof(arr)/ sizeof(arr[0]);
	
	printArr(arr, n);
	countingSort(arr, n);
	printArr(arr, n);
	
	system("pause");
}
