/*

*/
#include "common.h"

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
    PrintTitle(__FILE__);
    cout << "结果: " << endl;
    cout << ret << endl;
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}