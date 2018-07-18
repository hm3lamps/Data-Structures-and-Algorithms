#include<iostream>
#include<map>
#include<iterator>
#include<list>
using namespace std;

class lruCache{
	list<int> cacheKey;
	map<int, list<int>::iterator> ma;
	int cacheSize;
	
	public:
		lruCache(int);
		void refer(int);
		void display();
};

lruCache :: lruCache(int item){
	cacheSize = item;
}
void lruCache::refer(int key){
	if(ma.find(key) == ma.end()){
		if(cacheKey.size() == cacheSize){
			int last = cacheKey.back();
			cacheKey.pop_back();
			ma.erase(last);
		}
	}
	else{
		cacheKey.erase(ma[key]);
	}
	cacheKey.push_front(key);
	ma[key] = cacheKey.begin();
}
void lruCache::display(){
	list<int>::iterator it;
	for(it= cacheKey.begin(); it!=cacheKey.end(); it++){
		std:cout<<(*it)<<" ";
	}
	std::cout<<endl;
}

int main(){
	
	lruCache ca(4);
	ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
	system("pause");
}

