/*
216. 组合总和 III
https://leetcode-cn.com/problems/combination-sum-iii/
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>

using namespace std;

void PrintTitle(void)
{
    string path(__FILE__);
    auto path_suffix = path.find_last_of('.');
    auto path_presuffix = path.find_last_of('/') + 1;
    cout << "[题目：" << path.substr(path_presuffix, path_suffix - path_presuffix) << "]" << endl;
}

//回溯模板
void backtracking(int startIndex, int k, int sum, int tmp_sum, vector<int> &path, vector<vector<int>> &ret)
{
    //退出条件
    if (k == 0 && tmp_sum == sum)
    {
        ret.push_back(path);
        return;
    }
    if (tmp_sum > sum)
    {
        return;
    }

    //由于部分节点明显不满足要求，可以剪枝去除
    for (int i = startIndex; i <= 9; ++i)
    {
        //处理节点
        path.push_back(i);
        tmp_sum += i;
        //递归
        backtracking(i + 1, k - 1, sum, tmp_sum, path, ret);
        tmp_sum -= i;
        //撤销节点处理
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ret;
    vector<int> path;
    backtracking(1, k, n, 0, path, ret);
    return ret;
}

int main()
{
    int n = 15;
    int k = 4;

    auto start = std::chrono::steady_clock::now();
    auto ret = combinationSum3(k, n);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    PrintTitle();
    cout << "结果: " << endl;
    for (vector<int> comb : ret)
    {
        cout << "[  ";
        for (int i : comb)
        {
            cout << i << "  ";
        }
        cout << ']' << endl;
    }
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}