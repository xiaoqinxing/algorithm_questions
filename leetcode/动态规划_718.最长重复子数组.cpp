/*
718. 最长重复子数组
https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。


示例：

输入：
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出：3
解释：
长度最长的公共子数组是 [3, 2, 1] 。
 

提示：

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*/
#include "common.h"
#include "timer.h"

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    //以i结尾的最长公共子数组
    vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size()));
    int ret = 0;

    for (int i = 0; i < nums1.size(); ++i)
    {
        if (nums1[i] == nums2[0])
        {
            dp[i][0] = 1;
            ret = 1;
        }
    }
    for (int j = 0; j < nums2.size(); ++j)
    {
        if (nums2[j] == nums1[0])
        {
            dp[0][j] = 1;
            ret = 1;
        }
    }
    //因为此处的i和j需要大于1，可以把数组整体扩大1，这样就不需要前面的初始化了！！！
    for (int i = 1; i < nums1.size(); ++i)
    {
        for (int j = 1; j < nums2.size(); ++j)
        {
            if (nums1[i] == nums2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > ret)
                {
                    ret = dp[i][j];
                }
            }
        }
    }
    return ret;
}

int main()
{
    //input init
    // vector<int> nums1 = {1, 2, 3, 2, 1};
    // vector<int> nums2 = {3, 2, 1, 4, 7};
    vector<int> nums1 = {1, 0, 0, 0, 1};
    vector<int> nums2 = {1, 0, 0, 1, 1};

    //function
    Timer t;
    auto ret = findLength(nums1, nums2);
    t.printElapsed();

    //print log
    PrintTitle(__FILE__);
    PrintVal(ret);
    return 0;
}