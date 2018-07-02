#include<iostream>
using namespace std;

int fibDP(int n){
	int fibNum[n+1];
	int i ;
	fibNum[0]=0;
	fibNum[1]=1;
	for(i =2; i<=n;i++){
		fibNum[i]= fibNum[i-1]+ fibNum[i-2];
	}
	
	return fibNum[n];
}

int main(){
	int n = 9;
	std::cout<< n<<"th fibonacci number is:" << fibDP(n)<<std::endl;
	system("pause");
}
