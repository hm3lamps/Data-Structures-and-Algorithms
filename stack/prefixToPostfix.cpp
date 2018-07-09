#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char x){
	switch(x){
		case '+':
		case '-':
		case '/':
		case '*':
			return true;
	}
	return false;
}

string pretoPostFix( string pre){
	stack <string> s;
	int length = pre.size();
	
	for(int i =  length-1; i>=0; i--){
		if(isOperator(pre[i])){
			string op1 = s.top(); s.pop();
			string op2 = s.top(); s.pop();
			
			string temp = op1+op2+ pre[i];
			s.push(temp);
		}
		else{
			s.push(string(1, pre[i]));
		}
	}
	return s.top();
}
int main(){
	string pre = "*-A/BC-/AKL";
	std::cout<<"Converting  Given prefix String to Postfix: "<<pretoPostFix(pre)<<endl;
	system("pause");
}
