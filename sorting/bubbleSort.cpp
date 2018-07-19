#include<iostream>

using namespace std;

void swap(int* p1, int *p2){
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void printArr(int arr[], int n){
	for(int i = 0; i < n; i++)
		std::cout << arr[i] <<"->";
	std::cout << endl;
}

void bubbleSort(int arr[], int n){
	int i, j;
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

int main(){
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/ sizeof(arr[0]);
	
	printArr(arr, n);
	bubbleSort(arr, n);
	printArr(arr, n);
	system("pause");
	
}
