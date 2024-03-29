#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <chrono>
#include <unordered_set>
#include <queue>
#include <list>
#include <set>

using namespace std;

template <typename Container>
void Print1DMatrix(Container &container, bool prefix = true)
{
    if (prefix == true)
    {
        cout << "结果: ";
    }
    cout << "[ ";
    for (auto i = container.begin(); i != container.end(); ++i)
    {
        cout << *i << ' ';
    }
    cout << "]" << endl;
    if (prefix == true)
    {
        cout << endl;
    }
}

template <typename T>
void Print2DMatrix(T &matrix, bool prefix = true)
{
    if (prefix == true)
    {
        cout << "结果: ";
    }
    cout << "{" << endl;

    for (auto i : matrix)
    {
        Print1DMatrix(i, false);
    }
    cout << "}" << endl;
    if (prefix == true)
    {
        cout << endl;
    }
}

template <typename T>
void PrintVal(T &val, bool prefix = true)
{
    if (prefix == true)
    {
        cout << "结果: ";
    }
    cout << val << endl;
    if (prefix == true)
    {
        cout << endl;
    }
}

#define PRINT(x)        \
    do                  \
    {                   \
        auto ret = (x); \
        PrintVal(ret);  \
    } while (0);

#define PRINT1D(x)          \
    do                      \
    {                       \
        auto ret = (x);     \
        Print1DMatrix(ret); \
    } while (0);

#define PRINT2D(x)          \
    do                      \
    {                       \
        auto ret = (x);     \
        Print2DMatrix(ret); \
    } while (0);

inline void PrintTitle(string filename)
{
    string path(filename);
    auto path_suffix = path.find_last_of('.');
    auto path_presuffix = path.find_last_of('/') + 1;
    cout << "[题目：" << path.substr(path_presuffix, path_suffix - path_presuffix) << "]" << endl;
}

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
                                       { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
                        { return !isspace(ch); })
                    .base(),
                input.end());
}

#define TEST(func, nums, printinput, printret) \
    {                                          \
        cout << "输入: ";                      \
        input = nums;                          \
        printinput(input, false);              \
        t.reset();                             \
        ret = func(input);                     \
        t.printElapsed();                      \
        printret(ret);                         \
        cout << endl;                          \
    }

#define INIT(inputtype, outputtype) \
    Timer t;                        \
    inputtype input;                \
    outputtype ret;

#endif