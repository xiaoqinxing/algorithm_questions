#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>

using namespace std;
void PrintTitle(void)
{
    string path(__FILE__);
    auto path_suffix = path.find_last_of('.');
    auto path_presuffix = path.find_last_of('/') + 1;
    cout << "[题目：" << path.substr(path_presuffix, path_suffix - path_presuffix) << "]" << endl;
}

int function(int nums)
{
    return nums;
}

int main()
{
    //input init
    int nums = 1;

    //function
    auto start = std::chrono::steady_clock::now();
    auto ret = function(nums);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    //print log
    PrintTitle();
    cout << "结果: " << ret << endl;
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}