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
#include "timer.h"
/*
题解：
这道题目和39.组合总和如下区别：

1. 本题candidates 中的每个数字在每个组合中只能使用一次。
2. 本题数组candidates的元素是有重复的，而39.组合总和是无重复元素的数组candidates

如果把所有组合求出来，再用set或者map去重，这么做很容易超时！所以要在搜索的过程中就去掉重复组合。

组合问题可以抽象为树形结构，那么“使用过”在这个树形结构上是有两个维度的，
一个维度是同一树枝上使用过，一个维度是同一树层上使用过。

回看一下题目，元素在同一个组合内是可以重复的，怎么重复都没事，但两个组合不能相同。
所以我们要去重的是同一树层上的“使用过”，同一树枝上的都是一个组合里的元素，不用去重。
*/

void backtracking(vector<int> &candidates, int target, int tmp_sum,
                  int startIndex, vector<int> &used, vector<int> &path, vector<vector<int>> &ret)
{
    if (tmp_sum == target)
    {
        ret.push_back(path);
        return;
    }

    for (int i = startIndex; i < candidates.size() && tmp_sum + candidates[i] <= target; ++i)
    {
        // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
        // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
        // 要对同一树层使用过的元素进行跳过
        if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == 0)
        {
            continue;
        }
        tmp_sum += candidates[i];
        path.push_back(candidates[i]);
        used[i] = 1;
        backtracking(candidates, target, tmp_sum, i + 1, used, path, ret);
        tmp_sum -= candidates[i];
        used[i] = 0;
        path.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> path;
    vector<vector<int>> ret;
    //used正在使用的位置标记，可以用来判断是否在同一层，是否使用过
    vector<int> used(candidates.size());
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0, used, path, ret);
    return ret;
}

int main()
{
    //input init
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    //function
    auto start = std::chrono::steady_clock::now();
    auto ret = combinationSum2(nums, target);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    //print log
    PrintTitle(__FILE__);
    Print2DMatrix(ret);
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}