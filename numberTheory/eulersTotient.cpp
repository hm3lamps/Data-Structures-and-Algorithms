#include<iostream>
#include<math.h>
using namespace std;

int eulers(int n){
	float result = n;
	for(int p = 2; p <=  sqrt(n); p++ ){
		if(n%p ==0){
			while(n%p == 0) n= n/p;
			result = result *(1.0- 1.0/(float)p);
		}
	}
	if(n>1){
		result = result * (1.0-1.0/(float)n);
	}
	return (int)result;
}

int main(){
	int n = 6;
	std::cout<<"count for "<<n<<" is:" << eulers(n)<<std::endl;
	system("pause");
}


