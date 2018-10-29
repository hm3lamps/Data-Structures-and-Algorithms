#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
	
	double arr[] = {0.4, 0.6};
	
	double arr2[2][2] = {{ 0.8, 0.2},{0.1, 0.9}};
	
	double temp[] = {0.4, 0.6};
	
	for(int i =0; i< 25; i++){
		temp[0] = arr[0] * arr2[0][0] + arr[1] * arr2[1][0];
		temp[1] = arr[0] * arr2[0][1] + arr[1] * arr2[1][1];
		memcpy(arr, temp, 2*sizeof(double));
	}
	std::cout << arr[0] << " "<< arr[1] << endl;
	return 0;
}
