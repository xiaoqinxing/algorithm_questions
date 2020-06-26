#include <iostream>
using namespace std;
int func1(){
    int a=502,b=94278;
    long int c;
    cin >> a >> b;
    for(int i=1;i<=b;++i){
        c = a*i;
        if(c%b==0){
            cout << c <<endl;
            return 0;
        }
    }
    return -1;
}
int func2(){
    int a=502,b=94278;
    //cin >> a >> b;
    int c=a;
    int d = b;
    int m=a%b;
    while(m!=0){
        a=b;
        b=m;
        m=a%b;
    }
    cout << c*d/b <<endl;
    return 0;
}
//辗转相除法：辗转相除法是求两个自然数的最大公约数的一种方法，也叫欧几里德算法。
int gcd(int a,int b){
    int tmp;
    while(a%b){
        tmp=a;
        a =b;
        b=tmp%a;
    }
    return b;
}
int func3(){
    int a=502,b=94278;
    cin >> a >> b;
    cout << a*b/gcd(a,b) <<endl;
    return 0;
}
int main(){
    // func1();
    // func2();
    func3();
    return 0;
}