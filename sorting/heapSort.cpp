#include<iostream>

using namespace std;

void printArr(int arr[], int n){
	for(int i = 0; i < n; i++)
		std::cout << arr[i] <<"->";
	std::cout << endl;
}

void maxheapify(int arr[], int n , int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	
	if(l < n && arr[l] > arr[largest]) largest = l;
	if(r < n && arr[r] > arr[largest]) largest = r;
	
	if(largest != i){
		swap(arr[i], arr[largest]);
		maxheapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n){
	for(int i = n/2 -1; i>=0; i--){
		maxheapify(arr, n, i);
	}

	for(int i = n-1; i > 0; i--){
		swap(arr[0], arr[i]);
		maxheapify(arr, i, 0);
	}
}

int main(){
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(arr)/ sizeof(arr[0]);
	
	printArr(arr, n);
	heapSort(arr, n);
	printArr(arr, n);
	system("pause");
	
}
