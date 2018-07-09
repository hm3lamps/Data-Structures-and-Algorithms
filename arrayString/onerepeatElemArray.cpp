#include<iostream>
#include<numeric>
#include<map>
using namespace std;

//We are given an array arr[] of size n. Numbers are from 1 to (n-1) in random order. The array has only one repetitive element. We need to find the repetitive element.


int findrepeating(int arr[], int n){
	return accumulate(arr, arr+n, 0) - ((n-1)*n/2);
}

int findUsingHashing(int arr[], int n){
	map<int,int> freq;
	map<int, int>::iterator itr;
	for(int i = 0; i < n; i++){
		if(freq.find(arr[i])!= freq.end()){
			return arr[i];
		}
		freq[arr[i]] = i;
	}
}
int main(){
	int arr[] =  { 9, 8, 2, 6, 1, 8, 5, 3, 4, 7 };
	int n = sizeof(arr)/sizeof(arr[0]);
	std::cout << "repeating Number is: "<<findrepeating(arr, n)<<endl;
	std::cout<< "repeatingNumber using Hashing: "<<findUsingHashing(arr, n)<<endl;
	system("pause");
}
