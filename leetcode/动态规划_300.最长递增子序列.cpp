/*

*/
#include "common.h"
#include "timer.h"

int lengthOfLIS(vector<int> &nums)
{
    //以i结尾的最长递增子序列
    //注意初始化，都至少是1！！！ 不仅前几个值要初始化，dp数组也需要初始化
    vector<int> dp(nums.size(), 1);
    if (nums.size() == 1)
    {
        return 1;
    }
    if (nums.size() == 2)
    {
        return nums[0] < nums[1] ? 2 : 1;
    }
    dp[0] = 1;
    dp[1] = nums[0] < nums[1] ? 2 : 1;
    int ret = 0;
    for (int i = 2; i < nums.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (ret < dp[i])
        {
            ret = dp[i];
        }
    }
    // Print1DMatrix(dp);
    return ret;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    vector<int> nums({10, 9, 2, 5, 3, 7, 101, 18});

    //function
    Timer t;
    auto ret = lengthOfLIS(nums);
    t.printElapsed();
    PrintVal(ret);
    return 0;
}