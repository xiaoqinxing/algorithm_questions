#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>

using namespace std;

template <class T>
void PrintMatrix(T begin, T end)
{
    for (; begin != end; begin++)
    {
        cout << *begin << " ";
    }
    cout << endl;
}

int main()
{
    int ret = 0;
    string path(__FILE__);
    auto path_suffix = path.find_last_of('.');
    auto path_presuffix = path.find_last_of('/') + 1;
    auto start = std::chrono::steady_clock::now();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << "[题目：" << path.substr(path_presuffix, path_suffix - path_presuffix) << "]" << endl;
    cout << "结果: " << ret << endl;
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}