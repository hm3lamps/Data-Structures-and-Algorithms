#include<iostream>
#include<map>
#include<iterator>
using namespace std;


int minDelete(int arr[], int n){
	map<int,int> ::iterator itr;
	map<int,int> freq;
	for(int i =0; i<n; i++){
		freq[arr[i]]++;
	}
	int maxOccur= -1;
	for ( itr = freq.begin(); itr!= freq.end(); itr++){
			maxOccur = max(maxOccur, itr -> second);
		}
	return n-maxOccur ; 
}

// Minimum number of delete operations required to make array have same elements
int main(){
    std::cout<<"hello";
	int arr[] = {4, 3, 4, 4, 2, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	std::cout<<"minimum number of delete operations required are:"<<std::endl;
	std::cout<<minDelete(arr, n);
	std::cout<<endl;
	
	system("pause");
}
