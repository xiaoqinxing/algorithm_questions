/*
40. 组合总和 II
https://leetcode-cn.com/problems/combination-sum-ii/
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
*/
#include "common.h"

void backtracking(vector<int> &candidates, int target, int tmp_sum,
                  int startIndex, vector<int> &path, vector<vector<int>> &ret)
{
    if (tmp_sum == target)
    {
        ret.push_back(path);
        return;
    }
    if (tmp_sum > target)
    {
        return;
    }

    //如果已经知道下一层的sum会大于target，就没有必要进入下一层递归了。
    //可以做一些剪枝，比如将candidates排个序，在某个数之后明显不符合要求，就不需要进入递归了
    for (int i = startIndex; i < candidates.size() && tmp_sum + candidates[i] <= target; ++i)
    {
        tmp_sum += candidates[i];
        path.push_back(candidates[i]);
        backtracking(candidates, target, tmp_sum, i, path, ret);
        tmp_sum -= candidates[i];
        path.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> path;
    vector<vector<int>> ret;
    sort(candidates.begin(), candidates.end());

    backtracking(candidates, target, 0, 0, path, ret);
    return ret;
}

int main()
{
    //input init
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;

    //function
    auto start = std::chrono::steady_clock::now();
    auto ret = combinationSum(nums, target);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    //print log
    PrintTitle(__FILE__);
    cout << "结果: " << endl;
    for (vector<int> item : ret)
    {
        PrintContainer(item);
    }
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}