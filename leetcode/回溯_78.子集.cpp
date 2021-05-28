/*

*/
#include "common.h"
#include "timer.h"

void backtracking(vector<int> &nums, int startIndex, vector<int> &path, vector<vector<int>> &ret)
{
    if (startIndex > nums.size())
    {
        return;
    }
    ret.push_back(path);
    for (int i = startIndex; i < nums.size(); ++i)
    {
        path.push_back(nums[i]);
        backtracking(nums, i + 1, path, ret);
        path.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> path;
    vector<vector<int>> ret;
    backtracking(nums, 0, path, ret);
    return ret;
}

int main()
{
    //input init
    vector<int> nums = {1, 2, 3};

    //function
    auto start = std::chrono::steady_clock::now();
    auto ret = subsets(nums);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    //print log
    PrintTitle(__FILE__);
    Print2DMatrix(ret);
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}