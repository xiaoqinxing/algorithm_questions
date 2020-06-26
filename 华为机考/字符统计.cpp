// 如果统计的个数相同，则按照ASCII码由小到大排序输出 。如果有其他字符，则对这些字符不用进行统计。

// 实现以下接口：
// 输入一个字符串，对字符中的各个英文字符，数字，空格进行统计（可反复调用）
// 按照统计个数由多到少输出统计结果，如果统计的个数相同，则按照ASII码由小到大排序输出
// 清空目前的统计结果，重新统计
// 调用者会保证：
// 输入的字符串以‘\0’结尾。
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
bool greater_cmp(const pair<char,int> a,const pair<char,int> b){
    return a.second > b.second;
}
bool isBigger(const pair<char, int> &lhs, const pair<char, int> &rhs){
    if(lhs.second == rhs.second)
        return lhs.first < rhs.first;
    return lhs.second > rhs.second;
}
bool isBigger2(const pair<char, int> &lhs, const pair<char, int> &rhs){
    return lhs.second > rhs.second;
}
int main(){
    string str;
    while(cin>>str){
        map<char,int> m;
        for(int i=0;i<str.size();i++){
            ++m[str[i]];
        }
        vector<pair<char,int> > pvec(m.begin(),m.end());
        sort(pvec.begin(),pvec.end(),isBigger);
        //stable_sort(pvec.begin(),pvec.end(),isBigger2);
        for(vector<pair<char,int> >::iterator it=pvec.begin();it!=pvec.end();++it){
            cout << it->first;
        }
        // for(auto &p : pvec)
        //     cout << p.first;
        cout << endl;
    }
}
//定义的时候两个>需要分开来写，不然会重载运算符>>
//注意sort的比较函数的输入要加const
//对于相等的元素sort可能改变顺序，stable_sort保证排序后相等的元素次序不变