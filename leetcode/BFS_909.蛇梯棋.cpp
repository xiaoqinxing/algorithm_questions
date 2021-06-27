/*

*/
#include "common.h"
#include "test_tree.h"
#include "test_list.h"
#include "timer.h"

int snakesAndLadders(vector<vector<int>> &board)
{
    int len = board.size();
    int boardvaluesize = len * len;
    vector<int> boardvalue(boardvaluesize);
    int x = len - 1;
    int y = 0;
    int direction = 1;
    for (int i = 0; i < boardvalue.size(); ++i)
    {
        boardvalue[i] = board[x][y];
        y += direction;
        if (y > len - 1 || y < 0)
        {
            y -= direction;
            direction = -direction;
            x--;
        }
    }
    // Print1DMatrix(boardvalue);
    //bfs
    deque<int> q;
    q.push_back(0);
    int level = 0;
    int current = 0;
    int tmp;
    set<int> used;
    while (!q.empty())
    {
        len = q.size();
        Print1DMatrix(q);
        PrintVal(level);

        for (int i = 0; i < len; ++i)
        {
            current = q.front();
            q.pop_front();

            //退出
            if (current == boardvaluesize - 1)
            {
                return level;
            }
            for (int j = 1; j <= 6; j++)
            {
                tmp = current + j;
                if (tmp > boardvaluesize - 1 || tmp < 0)
                {
                    continue;
                }

                //跳跃
                if (boardvalue[current + j] != -1)
                {
                    tmp = boardvalue[current + j] - 1;
                }

                if (used.count(tmp))
                {
                    continue;
                }
                q.push_back(tmp);
                used.insert(tmp);
            }
        }
        level++;
    }

    return -1;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    // vector<vector<int>> board = {
    //     {-1, -1, -1, -1, -1, -1},
    //     {-1, -1, -1, -1, -1, -1},
    //     {-1, -1, -1, -1, -1, -1},
    //     {-1, 35, -1, -1, 13, -1},
    //     {-1, -1, -1, -1, -1, -1},
    //     {-1, 15, -1, -1, -1, -1}};
    vector<vector<int>> board = {{1, 1, -1},
                                 {1, 1, 1},
                                 {-1, 1, 1}};

    //function
    Timer t;
    auto ret = snakesAndLadders(board);
    t.printElapsed();
    PrintVal(ret);

    return 0;
}