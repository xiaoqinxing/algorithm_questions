/*
491. 递增子序列
给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是 2 。

 

示例：

输入：[4, 6, 7, 7]
输出：[[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
 

提示：

给定数组的长度不会超过15。
数组中的整数范围是 [-100,100]。
给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
*/
#include "common.h"
//子集问题不需要退出条件，因为for循环就是遍历了
//不用同一层重复元素的子集问题，可以用nums[i] == nums[i-1]进行判断，这样第一个不同的书一定是遍历到了的
//重复的数没有被遍历到
void backtracking(vector<int> &nums, int startIndex, vector<int> &path, vector<vector<int>> &ret)
{
    if (path.size() > 1)
    {
        ret.push_back(path);
    }
    unordered_set<int> uset;
    for (int i = startIndex; i < nums.size(); ++i)
    {
        if (uset.find(nums[i]) != uset.end())
            continue;
        if (!path.empty() && nums[i] < path.back())
            continue;
        path.push_back(nums[i]);
        uset.insert(nums[i]);
        backtracking(nums, i + 1, path, ret);
        path.pop_back();
    }
}
vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vector<vector<int>> ret;
    vector<int> path;
    backtracking(nums, 0, path, ret);
    return ret;
}

int main()
{
    //input init
    vector<int> nums = {4, 6, 7, 7};

    //function
    auto start = std::chrono::steady_clock::now();
    auto ret = findSubsequences(nums);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    //print log
    PrintTitle(__FILE__);
    cout << "结果: " << endl;
    Print2DMatrix(ret);
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}