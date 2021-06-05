/*
342. 4的幂
给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x

 

示例 1：

输入：n = 16
输出：true
示例 2：

输入：n = 5
输出：false
示例 3：

输入：n = 1
输出：true
 

提示：

-231 <= n <= 231 - 1
 

进阶：

你能不使用循环或者递归来完成本题吗？
*/
#include "common.h"
#include "test_tree.h"
#include "timer.h"

//循环
bool isPowerOfFour(int n)
{
    while (n >= 4 && n % 4 == 0)
    {
        n = n / 4;
    }
    if (n == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//递归
bool isPowerOfFour_II(int n)
{
    if (n >= 4 && n % 4 == 0)
        return isPowerOfFour_II(n / 4);
    else
        return n == 1;
}

//位运算
//可以发现它除以 3 的余数一定为 1
//4^x = (2*2)^x，一定是2的幂，2的幂可以用位运算：n*(n-1)判断
bool isPowerOfFour_III(int n)
{
    return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    int nums = 17;

    //function
    Timer t;
    auto ret = isPowerOfFour(nums);
    t.printElapsed();
    PrintVal(ret);

    ret = isPowerOfFour_II(nums);
    t.printElapsed();
    PrintVal(ret);

    ret = isPowerOfFour_III(nums);
    t.printElapsed();
    PrintVal(ret);

    return 0;
}