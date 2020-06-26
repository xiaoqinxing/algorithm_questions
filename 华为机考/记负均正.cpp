//从输入任意个整型数，统计其中的负数个数并求所有非负数的平均值，结果保留一位小数，如果没有非负数，则平均值为0
//本题有多组输入数据，输入到文件末尾，请使用while(cin>>)读入
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int a;
    int fushu_num=0;
    int zhenshu_num=0;
    long int zhenshu_sum=0;
    cout.fixed(1);
    while(cin >> a){
        if(a <0)
            ++fushu_num;
        else
        {
            ++zhenshu_num;
            zhenshu_sum += a;
        }
    }
    cout << fushu_num <<endl;
    //cout <<fixed<<setprecision(1)<< ((float)zhenshu_sum/zhenshu_num) << endl;
    cout << ((float)zhenshu_sum/zhenshu_num) << endl;
    return 0;
}
// 加了fixed意味着是固定点方式显示，所以这里的精度指的是小数位。如果没有的话，默认是有效数字
// 保留小数点后一位：cout <<fixed<<setprecision(1)<< ((float)zhenshu_sum/zhenshu_num) << endl;