/*

*/
#include "common.h"
#include "timer.h"

int fib(int n)
{
    vector<int> dp(n);
    if (n <= 1)
    {
        return 1;
    }
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    int nums = 4;

    //function
    Timer t;
    auto ret = fib(nums);
    t.printElapsed();
    PrintVal(ret);
    return 0;
}