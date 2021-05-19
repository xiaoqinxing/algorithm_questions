/*
674. 最长连续递增序列
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

 

示例 1：

输入：nums = [1,3,5,4,7]
输出：3
解释：最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。 
示例 2：

输入：nums = [2,2,2,2,2]
输出：1
解释：最长连续递增序列是 [2], 长度为1。
 

提示：

0 <= nums.length <= 104
-109 <= nums[i] <= 109
*/
#include "common.h"

//方法一：双指针
int findLengthOfLCIS(vector<int> &nums)
{
    int i = 0;
    int j = 0;
    int len = 1;
    for (j = 1; j < nums.size(); j++)
    {
        if (nums[j] > nums[j - 1])
        {
            len = max(len, j - i + 1);
        }
        else
        {
            i = j;
        }
    }
    return len;
}

//方法二：动态规划
int findLengthOfLCIS_II(vector<int> &nums)
{
    //以i结尾的最长递增序列
    vector<int> dp(nums.size(), 1);
    if (nums.size() <= 1)
    {
        return nums.size();
    }
    dp[0] = 1;
    int ret = 0;
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] > nums[i - 1])
            dp[i] = dp[i - 1] + 1;
        if (ret < dp[i])
            ret = dp[i];
    }
    // Print1DMatrix(dp);
    return ret;
}

//方法三：贪心算法 遇到nums[i + 1] > nums[i]的情况，count就++
int findLengthOfLCIS_III(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int result = 1; // 连续子序列最少也是1
    int count = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] > nums[i])
        { // 连续记录
            count++;
        }
        else
        { // 不连续，count从头开始
            count = 1;
        }
        if (count > result)
            result = count;
    }
    return result;
}

int main()
{
    //input init
    vector<int> nums = {1, 3, 5, 4, 7};

    //function
    int ret;
    Timer t;
    ret = findLengthOfLCIS(nums);
    t.printElapsed();
    ret = findLengthOfLCIS_II(nums);
    t.printElapsed();
    ret = findLengthOfLCIS_III(nums);
    t.printElapsed();

    //print log
    PrintTitle(__FILE__);
    cout << "结果: " << endl;
    cout << ret << endl;
    return 0;
}