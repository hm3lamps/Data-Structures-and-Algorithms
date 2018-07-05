#include<iostream>
#include<map>
#include<iterator>
using namespace std;

int getElemKOccur(int arr[], int n , int k ){
	map<int, int> arrMap ;
	map<int, int> ::iterator itr;
	for(int i = 0; i< n; i++){
		arrMap[arr[i]]++;
	}
	for(int i = 0; i<n; i++){
		if(arrMap[arr[i]] == k){
			return arr[i];
		}
	}
	return -1;
}
//get the first element that occur k times in an array else print -1
int main(){
 int arr [] ={1, 7, 4, 3, 4, 8, 7};
 int k = 2;
 int size = sizeof(arr)/sizeof(arr[0]);
 std::cout<<"element occuring k times in given array is:"<<std::endl;
 std::cout<< getElemKOccur(arr, size, k);
 std::cout<<endl;
 
 system("pause");
 return 0;
}
