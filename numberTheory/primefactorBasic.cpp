#include<iostream>
#include<math.h>
using namespace std;

void printPrimeFactor(int n){
	std::cout<< "unique prime factors are:";
	
	if(n%2 == 0) std::cout<< "2" << std::endl;
	while(n%2==0){
		n = n/2;
	}
	
	for(int i =3; i <= sqrt(n);i = i+2){
		if(n%i ==0) std::cout<<i<< std::endl;
		while(n%i == 0){
			n = n/i;	
		}
	}
	if(n>2) std::cout << n << std::endl;
}

int main(){
	int n = 315;
	printPrimeFactor(n);
	system("pause");
}
