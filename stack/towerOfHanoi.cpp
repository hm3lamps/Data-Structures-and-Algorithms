#include<iostream>
using namespace std;

void towerOfHanoi(int n, char from, char to, char inter){
	if(n==1){
		std::cout<<"Move 1 disk from "<<from <<" to: "<< to <<endl ;
		return;
	}
	towerOfHanoi(n-1, from, inter, to);
	std::cout<<"Move "<<n<<" disk from "<<from <<"to: " << to<<endl;
	towerOfHanoi(n-1, inter, to, from );
	
}

int main(){
	int n = 4;
	towerOfHanoi(n, 'A', 'C', 'B');
	system("pause");
}
