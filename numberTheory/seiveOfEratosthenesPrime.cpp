#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;

void seiveOfEratosthenes(int n){
	bool primeArr[n+1];
	memset(primeArr, true, sizeof(primeArr));
	
	for(int p = 2; p <=n; p++ ){
		if(primeArr[p] == true){
			for(int i = 2*p ;i<=n; i = i+p ) primeArr[i] = false;
		}	
	}
	for(int i = 2; i <=n; i++){
		if(primeArr[i]) std::cout<<i <<std::endl;
	}
}

int main(){
	seiveOfEratosthenes(30);
	system("pause");
}

