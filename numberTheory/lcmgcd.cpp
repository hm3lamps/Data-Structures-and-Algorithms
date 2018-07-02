#include<iostream>
using namespace std;

int calcGCD(int a, int b){
	if( a==0 || b==0) return 0;
	if(a==b) return a;
	if(a>b) return calcGCD(a-b, b);
	else return calcGCD(a, b-a);
}

int calcLCM(int a, int b , int gcd){
	return (a*b)/gcd;
}

int main(){
	int a = 15, b =7;
	int gcd =  calcGCD(a, b);
	int lcm = calcLCM(a, b, gcd);
	
	std::cout << "a and b are: "<<a <<" "<<b << std::endl;
	std::cout << "gcd is :" << gcd << std::endl;
	std::cout << "lcm is :" << lcm <<std::endl;
	
	system("pause");
}
