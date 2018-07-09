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

string postToPrefix(string post){
	
	stack<string> s;
	int length = post.size();
	
	for(int i = 0; i<length; i++){
		if(isOperator(post[i])){
			string op1 = s.top(); s.pop();
			string op2 = s.top(); s.pop();
			
			string temp = post[i] + op2 + op1;
			s.push(temp);			
		}
		else{
			s.push(string(1, post[i]));
		}
	}
	return s.top();
}

int main(){
	string post = "ABC/-AK/L-*";
	std::cout<< "postfix to prefix conversion:"<<postToPrefix(post)<<endl;
	system("pause");
}
