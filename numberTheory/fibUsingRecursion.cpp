#include<iostream>
using namespace std;

int fibRecursion(int n){
	if (n<=1) return n;
	return fibRecursion(n-1)+ fibRecursion(n-2);
}

int main(){
	
	int n = 9;
	std::cout << n<<"th Fib Number is: " << fibRecursion(n)<< std::endl;
	system("pause");
}
