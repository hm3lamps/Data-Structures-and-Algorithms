#include <iostream>
#include<stdio.h>

using namespace std;

int square (int n ){
	int sum = 0;
	while(n){
		sum = sum + (n%10)* (n%10);
		n /= 10;
	}
	return sum;
}

void isHappy (int n, bool arr[]){
	bool arr2[10000] = {false};
	int number = n;
	while(number!= 1 ){
		//std::cout << "came " << n <<endl;
		number = square(number);
		if(arr2[number - 1] == true){
			return;
		}
		else{
			arr2[number-1] = true;
		}

		if (number == 1){
			arr[n-1] = true;
			return;
		}
	}
}
int main(){
	// std::cout << "number isHappy:  " << isHappy(7);
	
	
 	bool arr[10000] = {false};
	for(int i = 1; i <= 100; i++){
		if(arr[i-1] == false){
			isHappy( i, arr);
		}
	}
	
	for(int i = 1;  i <=100; i++){
		if(arr[i-1] == true) std::cout << i <<endl;
		
	}
	 	
}
