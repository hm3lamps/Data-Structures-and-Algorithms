#include <iostream>
using namespace std;


int binarySearch(int arr[], int search, int start, int end){
	//cout << search <<endl;
	if(end >= start){
		int mid = start + (end- start)/2	;
		if(arr[mid]== search) 
			return mid;
		if(arr[mid] > search )
			return binarySearch(arr, search, start, mid-1);
		else
			return binarySearch(arr, search, mid+1, end);
		}
	return -1;
}

int main(){
	int arr[] = {2, 5, 6, 8, 9};
	int nelem =  sizeof(arr)/ sizeof(arr[0]);
	int search = 90;
	int result = binarySearch(arr, search, 0, nelem-1);
	if( result == -1){
		cout << "element doesnt exists";
	}
	else{
		cout<< "element is present at position "<< result+1;
	}
	return 0;
}
