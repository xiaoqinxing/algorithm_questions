/*
209. 长度最小的子数组
https://leetcode-cn.com/problems/minimum-size-subarray-sum/submissions/
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
 

提示：

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105
*/
#include "common.h"

int minSubArrayLen(int target, vector<int> &nums)
{
    int sum = 0;
    int i = 0;
    int minLen = nums.size();
    for (int j = 0; j < nums.size(); j++)
    {
        sum += nums[j];
        while (sum >= target)
        {
            minLen = min(minLen, j - i);
            sum -= nums[i];
            i++;
        }
    }
    return minLen == nums.size() ? 0 : minLen + 1;
}

int main()
{
    //input init
    // vector<int> nums = {1, 2, 3, 4, 5};
    // int target = 11;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    //function
    Timer t;
    auto ret = minSubArrayLen(target, nums);
    t.printElapsed();

    //print log
    PrintTitle(__FILE__);
    cout << "结果: " << endl;
    cout << ret << endl;
    return 0;
}