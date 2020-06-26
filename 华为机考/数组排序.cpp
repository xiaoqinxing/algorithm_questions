// 输入整型数组和排序标识，对其元素按照升序或降序进行排序（一组测试用例可能会有多组数据）

// 接口说明

// 原型：

// void sortIntegerArray(Integer[] pIntegerArray, int iSortFlag);

// 输入参数：

// Integer[] pIntegerArray：整型数组

// int  iSortFlag：排序标识：0表示按升序，1表示按降序

// 输出参数：

// 无

// 返回值：

// void

#include <iostream> 
#include <algorithm> 
  
using namespace std;
    
int main(void) 
{ 
    int n;
    while ( cin >> n )
    {
        int A[n], i = n-1, tag;
        for (i = 0; i < n; i++)
            cin >> A[i];
        cin >> tag;
        sort(A, A+n);
        if (tag == 1)
            reverse(A, A+n);
        for (i = 0; i < n-1; i++)
            cout << A[i] << ' ';
        cout << A[n-1] << endl;
    }    
}