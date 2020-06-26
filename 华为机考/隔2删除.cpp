#include <iostream>
#include <list>
using namespace std;
int main(){
	list<int>* a;
	int value=0;
	int size;
	list<int>::iterator it;
	while(cin>>size){
		if(size>1000) size=1000;
		a = new list<int>(size);
		for(it = a->begin();it!=a->end();++it){
			*it = value;
			++value;
		}
		it = a->begin();
		while(a->size()>1){
			++it;
			if(it ==a->end()) it = a->begin();
			++it;
			if(it ==a->end()) it = a->begin();
			it = a->erase(it);
			if(it ==a->end()) it = a->begin();
		}
		cout << a->front() << endl;
        delete a;
        value = 0;
	}
}