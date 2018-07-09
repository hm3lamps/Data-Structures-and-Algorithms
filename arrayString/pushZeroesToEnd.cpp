#include<iostream>
using namespace std;

pushZeroesToEnd(int arr[], int n ){
	int count = 0;
	for(int i = 0; i<n; i++){
		if(arr[i] != 0){
			arr[count] = arr[i];
			count++; 	
		}
	}	
	while(count<n){
		arr[count] = 0;
		count++;
	}
}
//push zeroes to end without changing order of non zero elements
int main(){
	int arr[] =  {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	pushZeroesToEnd(arr, n);
	for(int i = 0; i<n ; i++){
		std::cout<< arr[i]<<" ";	
	}
	system("pause");
}
