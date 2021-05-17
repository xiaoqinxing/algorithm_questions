/*

*/
#include "common.h"

void backtracking(vector<int> &nums, int startIndex,
                  vector<int> &path, vector<vector<int>> &ret)
{
    ret.push_back(path);
    for (int i = startIndex; i < nums.size(); ++i)
    {
        if (i > startIndex && nums[i] == nums[i - 1])
        {
            continue;
        }
        path.push_back(nums[i]);
        backtracking(nums, i + 1, path, ret);
        path.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<int> path;
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    backtracking(nums, 0, path, ret);
    return ret;
}

int main()
{
    //input init
    vector<int> nums = {1, 2, 2};

    //function
    auto start = std::chrono::steady_clock::now();
    auto ret = subsetsWithDup(nums);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    //print log
    PrintTitle(__FILE__);
    cout << "结果: " << endl;
    for (auto tmp : ret)
    {
        PrintContainer(tmp);
    }
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}