#include<bits/stdc++.h>

using  namespace std;

void shellSort(int arr[], int n){
	for(int gap = n/2; gap > 0; gap /= 2){
		for(int i = gap; i < n; i++){
			int temp = arr[i];
			
			int j;
			
			for(j = i; j >= gap && arr[j - gap] > temp; j -= gap ){
				arr[j] = arr[j-gap];
			}
			arr[j] = temp;
		}
	}
}

void printArr(int arr[], int n){
	for(int i = 0; arr[i]; i++){
		std::cout<<arr[i]<<"->";
	}
	std::cout<<endl;
}	

int main(){
	int arr[] = {12, 34, 54, 2, 3};
	int n =sizeof(arr)/sizeof(arr[0]);
	
	printArr(arr, n);
	shellSort(arr, n);
	printArr(arr, n);
	
	system("pause");
}
