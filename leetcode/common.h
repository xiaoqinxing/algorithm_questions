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
void Print1DMatrix(Container container)
{
    cout << "[ ";
    for (auto i = container.begin(); i != container.end(); ++i)
    {
        cout << *i << ' ';
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
        Print1DMatrix(i);
    }
}

using namespace std::chrono;
class Timer
{
public:
    Timer() : m_begin(high_resolution_clock::now()) {}
    void reset() { m_begin = high_resolution_clock::now(); }
    //默认输出秒
    double elapsed() const
    {
        return duration_cast<duration<double>>(high_resolution_clock::now() - m_begin).count();
    }

    //微秒
    int64_t elapsed_micro() const
    {
        return duration_cast<chrono::microseconds>(high_resolution_clock::now() - m_begin).count();
    }

    inline void printElapsed()
    {
        auto m_end = elapsed();
        cout << "耗时: " << m_end << "s" << endl;
        reset();
    }

private:
    time_point<high_resolution_clock> m_begin;
};
#endif