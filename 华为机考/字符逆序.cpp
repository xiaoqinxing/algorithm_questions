//将一个字符串str的内容颠倒过来，并输出。str的长度不超过100个字符。 如：输入“I am a student”，输出“tneduts a ma I”。
#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    char tmp;
    int len;
    getline(cin,str);
    len = str.size();
    for(int i=0;i<len/2;i++){
        tmp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = tmp;
    }
    cout << str << endl;
    return 0;
}
//输入一行是getline(cin,str);