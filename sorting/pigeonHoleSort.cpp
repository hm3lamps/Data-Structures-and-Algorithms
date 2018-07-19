#include <bits/stdc++.h>

using namespace std;

void pigeonhole(int arr[], int n){
	int min = arr[0];
	int max = arr[0];
	
	for(int i = 0; i < n; i++){
		if(min > arr[i]) min = arr[i];
		if(max < arr[i]) max = arr[i];
	}
	int range =  max-min+1;
	vector<int> holes[range];
	for(int i =0; i < n; i++){
		holes[arr[i]-min].push_back(arr[i]);
	}
	
	int index = 0;
	for(int i = 0; i < range; i++){
		vector<int>::iterator it;
		for(it = holes[i].begin(); it!=holes[i].end(); ++it){
			arr[index++] = *it;
		}
	}
}

int main(){
	int arr[] = {8, 3, 2, 7, 4, 6, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	pigeonhole(arr, n);
	
	for(int i = 0; arr[i]; i++)
		std:cout<<arr[i]<<"->";
	std::cout<<endl;
	system("pause");
}
