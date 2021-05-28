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
void Print2DMatrix(T &matrix)
{
    cout << "结果: {" << endl;
    for (auto i : matrix)
    {
        Print1DMatrix(i, false);
    }
    cout << "}" << endl
         << endl;
}

template <typename T>
void PrintVal(T &val)
{
    cout << "结果: ";
    cout << val << endl;
    cout << endl;
}

inline void PrintTitle(string filename)
{
    string path(filename);
    auto path_suffix = path.find_last_of('.');
    auto path_presuffix = path.find_last_of('/') + 1;
    cout << "[题目：" << path.substr(path_presuffix, path_suffix - path_presuffix) << "]" << endl;
}

#endif