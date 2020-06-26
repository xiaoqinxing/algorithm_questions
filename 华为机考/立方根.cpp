#include <iostream>
#include <math.h>
using namespace std;
double myabs(double n){
    return n>0?n:-n;
}
int func1(){
    int a;
    float x=1;
    cin >> a;
    cout.precision(2);
    while(myabs(x*x*x-a)>1e-7){
        x=x-(x*x*x-a)/(3*x*x);
    }
    cout << x << endl;
    return 0;
}
int func2(){
    cout.precision(2);
    int a;
    cin >> a;
    cout << powf(a,1.0/3) << endl;
    return 0;
}
int main(){
    func1();
    //func2();
    return 0;
}