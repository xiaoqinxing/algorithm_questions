// 问题描述：给出4个1-10的数字，通过加减乘除，得到数字为24就算胜利
// 输入：
// 4个1-10的数字。[数字允许重复，但每个数字仅允许使用一次，测试用例保证无异常数字]
// 输出：
// true or false
#include <iostream>
#include <set>
using namespace std;
#define POSSIBLE_NUM 6

void double_result(int a, int b, float *ret)
{
    ret[0] = a + b;
    ret[1] = a - b;
    ret[2] = a * b;
    ret[4] = b - a;
    if(b == 0)
        ret[3] = -999;
    else
        ret[3] = a / b;

    if(a == 0)
        ret[5] = -999;
    else
        ret[5] = b/a;
}
void find_others(int input, int* a){        
    int num =0;                                                                                      
    for(int i=2;i<5;i++){
        if(input != i){
            a[num] = i;
            num++;
        }
    }
}
int main()
{
    int a[4];
    int right_i[2];
    float left[POSSIBLE_NUM],right[POSSIBLE_NUM],all_ret[POSSIBLE_NUM];
    set<float> ret;
    //可以简化成两两相加，两两相乘
    //由于+和*符合交换律，可以算出两个数所有的可能
    //分成两个部分，左边和右边，最后在结合到一起
    while (cin >> a[0] >> a[1] >> a[2] >> a[3])
    {
        for(int i=0;i<3;i++){
            double_result(a[0],a[i+1],left);
            find_others(i+1,right_i);
            double_result(right_i[0],right_i[1],right);
            for(int j=0;j<6;j++){
                for(int k=0;k<6;k++){
                    double_result(left[j],right[k],all_ret);
                    for(int m=0;m<6;m++){
                        ret.insert(all_ret[m]);
                    }
                }
            }
        }
        for(auto c : ret){
            cout << c << ' ';
        }
        cout <<endl;
        if(ret.find(24) != ret.end())
            cout << "true" <<endl;
        else
            cout << "false" << endl;
        
    }
}
