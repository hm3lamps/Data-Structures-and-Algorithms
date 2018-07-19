#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void bucketSort( float arr[], int n){
	vector<float> h[n];
	
	for(int i = 0; i < n; i++){
		int bi = n * arr[i];
		h[bi].push_back(arr[i]);
	}
	
	for(int i = 0; i < n; i++){
		sort(h[i].begin(), h[i].end());
	}
	
	int index = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < h[i].size(); j++){
			arr[index++] = h[i][j];
		}
	}
}

void printArr(float arr[], int n){
	for(int i = 0 ; i < n ; i++){
		std::cout << arr[i] <<"->";
	}
	std::cout<<endl;
}

int main(){
	float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printArr(arr, n);
	bucketSort(arr, n);
	printArr(arr, n);
	
	system("pause");
}
