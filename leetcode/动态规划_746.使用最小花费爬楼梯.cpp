/*

*/
#include "common.h"

int minCostClimbingStairs(vector<int> &cost)
{
    int len = cost.size();
    vector<int> dp(len + 1);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i < len + 1; ++i)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    PrintContainer(dp);
    return dp[len];
}

int main()
{
    //input init
    vector<int> nums = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    // vector<int> nums = {10, 15, 20};

    //function
    auto start = std::chrono::steady_clock::now();
    auto ret = minCostClimbingStairs(nums);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    //print log
    PrintTitle(__FILE__);
    cout << "结果: " << endl;
    cout << ret << endl;
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}