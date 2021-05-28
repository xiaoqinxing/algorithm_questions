/*
70. 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
*/
#include "common.h"
#include "timer.h"

int climbStairs(int n)
{
    if (n <= 1)
        return n; // 因为下面直接对dp[2]操作了，防止空指针
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    { // 注意i是从3开始的
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    int nums = 10;

    //function
    Timer t;
    auto ret = climbStairs(nums);
    t.printElapsed();
    PrintVal(ret);

    return 0;
}