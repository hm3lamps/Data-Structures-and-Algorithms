#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
int drawdown(int arr[], int n){

	int answer = arr[0];
	int maxVal = 0;
	for(int i = 1; i < n; i++){
		answer = max(answer, arr[i]);
		maxVal = max(maxVal, answer - arr[i]);
	}
	return maxVal;
} 

int main(){
	int arr[] = {2,6,4,3,1};
	int n = sizeof(arr)/ sizeof(arr[0]);
	std::cout <<"max drawdown is: " << drawdown(arr,n) << endl;
}
