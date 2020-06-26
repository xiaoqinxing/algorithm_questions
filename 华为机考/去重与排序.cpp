#include <iostream>
#include <set>
using namespace std;
int main(){
	int n,array;
    while(cin >> n){
        set<int> students;
        for(;n>0;--n){
            cin >> array;
            students.insert(array);
        }
        for(set<int>::iterator students_it=students.begin(); students_it!=students.end();++students_it)
            cout << *students_it << endl;
        students.clear();
    }
	return 0;
}