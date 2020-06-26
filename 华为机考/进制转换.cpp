#include <iostream>
#include <string>
using namespace std;
int main1(){
    char a;
    int len;
    int sum;
    while(cin >> a){
        cin >> a;
        sum = 0;
        while(a!='\n'){
            a = cin.get();
            if(a>='0' && a<='9')
                a = a-'0';
            else if(a>='a' && a<='f')
                a = a - 'a'+10;
            else if(a>='A' && a<='F')
                a = a - 'A'+10;
            else
                break;
            sum = sum*16+a;
        }
        cout << sum <<endl;
    }
    return 0;
}
int main2(){
 int a; 
    while(cin>>hex>>a){
    cout<<a<<endl;
    }
}
int main(){
    string a; 
    cin>>a;
    cout<<a<<endl;
}
