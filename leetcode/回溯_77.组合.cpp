/*
77. 组合
https://leetcode-cn.com/problems/combinations/
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include "common.h"
#include "timer.h"

//回溯模板
void backtracking(int n, int k, int startIndex, vector<int> &path, vector<vector<int>> &ret)
{
    //退出条件
    if (k == 0)
    {
        ret.push_back(path);
        return;
    }

    //由于部分节点明显不满足要求，可以剪枝去除
    for (int i = startIndex; i <= n - k + 1; ++i)
    {
        //处理节点
        path.push_back(i);
        //递归
        backtracking(n, k - 1, i + 1, path, ret);
        //撤销节点处理
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ret;
    vector<int> path;
    backtracking(n, k, 1, path, ret);
    return ret;
}

int main()
{
    int n = 5;
    int k = 3;

    auto start = std::chrono::steady_clock::now();
    auto ret = combine(n, k);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    PrintTitle(__FILE__);
    Print2DMatrix(ret);
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}