#include<iostream>
#include<map>
#include<iterator>

using namespace std;

int maxDistance(int arr[], int n){
	map<int, int> occur;
	map<int, int>::iterator itr;
	int maxDistance = 0;
	for (int i = 0; i<n; i++){
		if(occur.find(arr[i]) ==  occur.end()){
			occur[arr[i]] = i;
		}
		else{
			maxDistance = max(maxDistance, i - occur[arr[i]]);
		}
	}
	return maxDistance;
}

int main(){
	int arr[] =  {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
	int size =  sizeof(arr)/sizeof(arr[0]);
	std::cout<<"max distance is:"<<std::endl;
	std::cout<<maxDistance(arr, size);
	std::cout<<endl;
	system("pause");
}
