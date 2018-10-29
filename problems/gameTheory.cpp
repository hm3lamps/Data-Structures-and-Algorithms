#include<iostream>
#include<iostream.h>

using namespace std;


int maxgain(int arr[], int start , int end ,int n){
	
	return max(arr[start] +  maxgain(arr, start+1, end, n), arr[end] +  m);
}
int main(){
	int arr[] = {5,3,7,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	std::cout << "Max Gain is : "<< e
	
}
