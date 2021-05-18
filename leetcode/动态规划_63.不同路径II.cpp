/*
63. 不同路径 II
https://leetcode-cn.com/problems/unique-paths-ii/
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？



网格中的障碍物和空位置分别用 1 和 0 来表示。

 

示例 1：


输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
示例 2：


输入：obstacleGrid = [[0,1],[0,0]]
输出：1
 

提示：

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] 为 0 或 1
*/
#include "common.h"

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int height = obstacleGrid.size();
    int width = obstacleGrid[0].size();
    vector<vector<int>> dp(height, vector<int>(width));
    if (obstacleGrid[0][0] == 0)
        dp[0][0] = 1;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (obstacleGrid[i][j] == 0)
            {
                if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
    }
    Print2DMatrix(dp);
    return dp[height - 1][width - 1];
}

int main()
{
    //input init
    // vector<vector<int>> obstacleGrid = {
    //     {0, 0, 0},
    //     {0, 1, 0},
    //     {0, 0, 0}};
    vector<vector<int>> obstacleGrid = {
        {1}};

    //function
    auto start = std::chrono::steady_clock::now();
    auto ret = uniquePathsWithObstacles(obstacleGrid);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    //print log
    PrintTitle(__FILE__);
    cout << "结果: " << endl;
    cout << ret << endl;
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}