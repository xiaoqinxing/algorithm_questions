#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>
#include <unordered_set>

using namespace std;

template <typename Container>
void PrintContainer(Container container)
{
    cout << "[ ";
    for (auto i : container)
    {
        cout << i << ' ';
    }
    cout << "]" << endl;
}

inline void PrintTitle(string filename)
{
    string path(filename);
    auto path_suffix = path.find_last_of('.');
    auto path_presuffix = path.find_last_of('/') + 1;
    cout << "[题目：" << path.substr(path_presuffix, path_suffix - path_presuffix) << "]" << endl;
}

template <typename T>
void Print2DMatrix(T matrix)
{
    for (auto i : matrix)
    {
        PrintContainer(i);
    }
}
#endif