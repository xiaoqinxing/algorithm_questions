// 连续输入字符串(输出次数为N,字符串长度小于100)，请按长度为8拆分每个字符串后输出到新的字符串数组，

// 长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。

// 首先输入一个整数，为要输入的字符串个数。

// 例如：

// 输入：2

// abc

// 12345789

// 输出：abc00000

// 12345678

// 90000000

#include <iostream>
#include <string>
using namespace std;
void print_less(string str){
    while(str.size()<8){
        str += '0';
    }
    cout << str <<endl;
    return;
}
int main(){
    int num=0;
    string str_example = "000000";
    string str;
    string str_out;
    int str_len;
    while(cin >> num){
        for(int i=0;i<num;i++){
            cin >> str;
            str_len = str.size();
            while(str.size() > 8){
                // cout << str_out.assign(str,0,8) << endl;
                // str.assign(str,8,string::npos);
                cout << str.substr(0,8) << endl;
                str = str.substr(8);
            }
            while(str.size()!=8){
                str += '0';
            }
            cout <<str << endl;
        }
    }
}
//string substr生成子字符串，可以用来截取部分字符串，第一个值是索引，第二个数是长度，和assign功能一致，不一样的是当表示从8到最后的时候，assign要加个npos
//如果是赋值i后面的字符串，str.assign(str,i,string::npos)或者是str.substr(8)