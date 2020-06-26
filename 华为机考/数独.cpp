#include <iostream>
#include <vector>
using namespace std;
typedef int ShuduMap[9][9];
class Point
{
public:
    int x;
    int y;
};
int possible_array[9] = {0};
int possible_num = 0;
int calc_possible(ShuduMap &array, int *out_array, int i, int j)
{
    int all_x_num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int all_y_num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x;
    int num = 0;
    for (x = 0; x < 9; ++x)
    {
        //判断一行中是否有重复的，如果有，返回-1。并找出0-9还缺什么数字
        if (array[i][x] != 0)
        {
            if (all_x_num[array[i][x]] != 0)
                all_x_num[array[i][x]] = 0;
            else
                return -1;
        }

        //判断一列中是否有重复的，如果有，返回-1。并找出0-9还缺什么数字
        if (array[x][j] != 0)
        {
            if (all_y_num[array[x][j]] != 0)
                all_y_num[array[x][j]] = 0;
            else
                return -1;
        }
    }

    //把行与列缺的数字进行比较，输出可能的点
    for (x = 1; x < 10; ++x)
    {
        if (all_x_num[x] != 0 && all_x_num[x] == all_y_num[x])
        {
            out_array[num] = all_x_num[x];
            ++num;
        }
    }
    return num;
}
void Print(ShuduMap &a)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}
void calc(vector<Point> &need_proc_point, ShuduMap &a, vector<Point>::iterator it)
{
    //clear data buffer
    vector<Point>::iterator it_clr;
    //如果所有的空点都跑完了，输出最后的矩阵
    if (it == need_proc_point.end())
    {
        Print(a);
        return;
    }

    //为了避免返回上一层之后，用的还是以前的数据，要将还没有用到的点清空
    for (it_clr = it; it_clr != need_proc_point.end(); ++it_clr)
    {
        a[it_clr->x][it_clr->y] = 0;
    }

    //计算这个空格可能的情况，possible_num就是有多少种可能，possible_array是返回的可能的点的数组。
    //如果没可能了，就直接退出
    possible_num = calc_possible(a, possible_array, it->x, it->y);
    if (possible_num <= 0)
        return;

    //对这几种可能进行枚举，首先将点进行赋值，然后计算下一个点
    for (int m = 0; m < possible_num; ++m)
    {
        a[it->x][it->y] = possible_array[m];
        ++it;
        calc(need_proc_point, a, it);
    }
    return;
}

int main()
{
    ShuduMap a = {{0}};
    int i, j;

    vector<Point> need_proc_point;
    vector<Point>::iterator point_it;
    Point p;
    //输入并找出需要求解的点，把这些点放到一个vector里面
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
            {
                p.x = i;
                p.y = j;
                need_proc_point.push_back(p);
            }
        }
    }

    //从第一个点开始递归
    calc(need_proc_point, a, need_proc_point.begin());
}
//遇到递归不要慌，从第一个开始推导，就像数学归纳法一样
//找到这一个和上一个的关系，找出共性
//最后需要一个终止条件,比如全部符合的时候进行输出。不符合条件的时候，结束递归。
//递归的时候需要注意数据的清空，防止混用
//迭代器*it后面跟东西的话，一定要加();(*it).x或者it->x
//如果是二维数组等比较麻烦的类型传递，可以先用typedef定义一下，然后用c++中的引用传递