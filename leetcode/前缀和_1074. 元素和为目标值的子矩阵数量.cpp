/*
1074. 元素和为目标值的子矩阵数量
给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。

子矩阵 x1, y1, x2, y2 是满足 x1 <= x <= x2 且 y1 <= y <= y2 的所有单元 matrix[x][y] 的集合。

如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 != x1'），那么这两个子矩阵也不同。

 

示例 1：



输入：matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
输出：4
解释：四个只含 0 的 1x1 子矩阵。
示例 2：

输入：matrix = [[1,-1],[-1,1]], target = 0
输出：5
解释：两个 1x2 子矩阵，加上两个 2x1 子矩阵，再加上一个 2x2 子矩阵。
示例 3：

输入：matrix = [[904]], target = 0
输出：0
 

提示：

1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8
*/
#include "common.h"
#include "tree.h"
#include "timer.h"

//暴力前缀和
int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
{
    vector<vector<int>> prefixSum(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
    for (int i = 1; i < prefixSum.size(); i++)
    {
        for (int j = 1; j < prefixSum[0].size(); ++j)
        {
            prefixSum[i][j] =
                matrix[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }
    // Print2DMatrix(prefixSum);

    int count = 0;
    for (int m = 1; m < prefixSum.size(); ++m)
    {
        for (int n = 1; n < prefixSum[0].size(); ++n)
        {
            // init
            for (int i = m; i < prefixSum.size(); ++i)
            {
                for (int j = n; j < prefixSum[0].size(); ++j)
                {
                    if (prefixSum[i][j] - prefixSum[i][j - n] - prefixSum[i - m][j] + prefixSum[i - m][j - n] == target)
                    {
                        count++;
                    }
                }
            }
            // vector<int> tmp({m, n});
            // Print1DMatrix(tmp);
            // Print2DMatrix(dp);
        }
    }
    return count;
}

//前缀和+两数之和
int numSubmatrixSumTarget_II(vector<vector<int>> &matrix, int target)
{
    vector<vector<int>> prefixSum(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
    for (int i = 1; i < prefixSum.size(); i++)
    {
        for (int j = 1; j < prefixSum[0].size(); ++j)
        {
            prefixSum[i][j] =
                matrix[i - 1][j - 1] + prefixSum[i - 1][j];
        }
    }
    Print2DMatrix(prefixSum);
    map<int, int> prefixMap;
    for (int i = 0; i < prefixSum.size(); ++i)
    {
        for (int j = i; j < prefixSum[0].size(); ++j)
        {
            prefixMap[j] = prefixSum[i][j] - prefixSum[i - 1][j];
        }
    }
    return 0;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    vector<vector<int>> nums = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}};
    // vector<vector<int>> nums = {
    //     {1, -1},
    //     {-1, 1}};
    int target = 0;

    //function
    Timer t;
    auto ret = numSubmatrixSumTarget(nums, target);
    t.printElapsed();
    PrintVal(ret);

    t.reset();
    ret = numSubmatrixSumTarget_II(nums, target);
    t.printElapsed();
    PrintVal(ret);

    return 0;
}