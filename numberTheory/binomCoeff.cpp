#include<iostream>
using namespace std;

int binomCoef ( int n, int k){
	if( k ==0 || k == n) return 1;
	return binomCoef(n-1, k) + binomCoef(n-1,k-1);
}


int min (int a, int b){
	return (a<b)? a:b;
}
int binomDP ( int n , int k){
	int c[n+1][k+1];
	int i, j;
	
	for(i = 0; i<=n; i++){
		for(j = 0; j<= min(i,k);j++){
			if(j == 0 || j == i){
				c[i][j] = 1;
			}
			else c[i][j]= c[i-1][j]+c[i-1][j-1];
		}
	}
	return c[n][k];
}
int main(){
	
	int c = 5, k=2;
	std::cout<< "using recursion"<<std::endl;
	std::cout<< " binomial coef for c,k "<< c<<" ,"<<k<< " is :" << binomCoef(c,k)<< std::endl;
	
	std::cout<< "using dynamic programming"<<std::endl;
	std::cout<< " binomial coef for c,k "<< c<<" ,"<<k<< " is :" << binomDP(c,k)<< std::endl;
	system("pause");
}
