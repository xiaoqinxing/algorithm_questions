/*
930. 和相同的二元子数组
给你一个二元数组 nums ，和一个整数 goal ，请你统计并返回有多少个和为 goal 的 非空 子数组。

子数组 是数组的一段连续部分。

 

示例 1：

输入：nums = [1,0,1,0,1], goal = 2
输出：4
解释：
有 4 个满足题目要求的子数组：[1,0,1]、[1,0,1,0]、[0,1,0,1]、[1,0,1]
示例 2：

输入：nums = [0,0,0,0,0], goal = 0
输出：15
 

提示：

1 <= nums.length <= 3 * 104
nums[i] 不是 0 就是 1
0 <= goal <= nums.length
*/
#include "common.h"
#include "test_tree.h"
#include "test_list.h"
#include "timer.h"

//双指针法
int numSubarraysWithSum_II(vector<int> &nums, int goal)
{
    int left = 0;
    int left2 = 0;
    int right = 0;
    int len = nums.size();
    int sum = 0;
    int sum_tmp = 0;
    int ret = 0;
    for (right = 0; right < len; right++)
    {
        sum += nums[right];
        while (sum > goal)
        {
            sum -= nums[left];
            left++;
        }
        left2 = left;
        sum_tmp = sum;
        while (sum_tmp == goal && left2 <= right)
        {
            sum_tmp -= nums[left2];
            left2++;
            ret++;
        }
    }
    return ret;
}

//前缀和
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int sum = 0;
    unordered_map<int, int> cnt;
    int ret = 0;
    for (auto &num : nums)
    {
        cnt[sum]++;
        sum += num;
        ret += cnt[sum - goal];
    }
    return ret;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    vector<int> nums = {1, 0, 1, 0, 1};
    // vector<int> nums = {0, 0, 0, 0, 0};

    //function
    Timer t;
    auto ret = numSubarraysWithSum(nums, 2);
    t.printElapsed();
    PrintVal(ret);

    t.reset();
    ret = numSubarraysWithSum_II(nums, 2);
    t.printElapsed();
    PrintVal(ret);

    return 0;
}