/*
815. 公交路线
给你一个数组 routes ，表示一系列公交线路，其中每个 routes[i] 表示一条公交线路，第 i 辆公交车将会在上面循环行驶。

例如，路线 routes[0] = [1, 5, 7] 表示第 0 辆公交车会一直按序列 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... 这样的车站路线行驶。
现在从 source 车站出发（初始时不在公交车上），要前往 target 车站。 期间仅可乘坐公交车。

求出 最少乘坐的公交车数量 。如果不可能到达终点车站，返回 -1 。

 

示例 1：

输入：routes = [[1,2,7],[3,6,7]], source = 1, target = 6
输出：2
解释：最优策略是先乘坐第一辆公交车到达车站 7 , 然后换乘第二辆公交车到车站 6 。 
示例 2：

输入：routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
输出：-1
 

提示：

1 <= routes.length <= 500.
1 <= routes[i].length <= 105
routes[i] 中的所有值 互不相同
sum(routes[i].length) <= 105
0 <= routes[i][j] < 106
0 <= source, target < 106
*/
#include "common.h"
#include "test_tree.h"
#include "test_list.h"
#include "timer.h"

int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{
    map<int, vector<int>> maproutes;
    for (int i = 0; i < routes.size(); ++i)
    {
        for (int j = 0; j < routes[i].size(); ++j)
        {
            maproutes[routes[i][j]].push_back(i);
        }
    }
    //车站，第几辆公交车
    deque<pair<int, int>> q;
    int len = 0;
    pair<int, int> current;
    int tmp;
    // set<pair<int, int>> routeset;
    unordered_set<int> routeset;
    int level = 0;
    for (int i = 0; i < maproutes[source].size(); i++)
    {
        q.push_back(make_pair(source, maproutes[source][i]));
    }
    while (!q.empty())
    {
        len = q.size();
        // Print1DMatrix(q);
        for (int i = 0; i < len; i++)
        {
            current = q.front();
            q.pop_front();
            if (current.first == target)
            {
                return level;
            }
            for (int j = 0; j < routes[current.second].size(); ++j)
            {
                tmp = routes[current.second][j];
                if (routeset.count(tmp))
                {
                    continue;
                }
                if (tmp == current.first)
                {
                    continue;
                }
                for (int k = 0; k < maproutes[tmp].size(); k++)
                {
                    pair<int, int> needproc = make_pair(tmp, maproutes[tmp][k]);
                    q.push_back(needproc);
                    routeset.insert(tmp);
                }
            }
        }
        level++;
    }
    return -1;
}

// int numBusesToDestination_II(vector<vector<int>> &routes, int source, int target)
// {
//     if (source == target)
//     {
//         return 0;
//     }
//     map<int, set<int>> maproutes;
//     deque<int> q;
//     map<int, int> m;
//     int len = routes.size();
//     for (int i = 0; i < len; i++)
//     {
//         for (int station : routes[i])
//         {
//             if (station == source)
//             {
//                 q.push_back(i);
//                 m[i] = 1;
//             }
//             maproutes[station].insert(i);
//         }
//     }
//     while (!q.empty())
//     {
//         int current = q.front();
//         int step = m[current];
//         for (int station : routes[current])
//         {
//             if (station == target)
//             {
//                 return step;
//             }
//             set<int> lines = maproutes[station];
//             if (lines.empty())
//             {
//                 continue;
//             }
//             for (int nr : lines)
//             {
//                 if (!m.count(nr))
//                 {
//                     m[nr] = step + 1;
//                     q.push_back(nr);
//                 }
//             }
//         }
//     }
//     return -1;
// }

int main()
{
    PrintTitle(__FILE__);
    //input init
    // vector<vector<int>> routes = {
    //     {1, 2, 7},
    //     {3, 6, 7}};

    vector<vector<int>> routes = {
        {5, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}};

    //function
    Timer t;
    auto ret = numBusesToDestination(routes, 9, 19);
    t.printElapsed();
    PrintVal(ret);

    t.reset();
    ret = numBusesToDestination_II(routes, 9, 19);
    t.printElapsed();
    PrintVal(ret);

    return 0;
}