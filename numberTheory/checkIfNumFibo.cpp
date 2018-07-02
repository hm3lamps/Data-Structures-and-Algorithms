#include<iostream>
#include<math.h>
using namespace std;

bool sqrtCheck(int num){
	int sqr = sqrt(num);
	return (sqr*sqr == num);
}
bool checkIfFibNum(int n){
	return sqrtCheck(5*n*n +4)|| sqrtCheck(5*n*n -4);
}

int main(){
	int n  = 3;
	std::cout<<n<<"th number is fib number 0 false, 1 true?" <<std::endl <<checkIfFibNum(n) <<std::endl;
	system("pause");
}
