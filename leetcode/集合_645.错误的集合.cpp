/*

*/
#include "common.h"
#include "test_tree.h"
#include "test_list.h"
#include "timer.h"

//哈希表/set
vector<int> findErrorNums(vector<int> &nums)
{
    unordered_set<int> s;
    vector<int> ret(2);
    int len = 0;
    for (int i : nums)
    {
        s.insert(i);
        if (s.size() > len)
        {
            len++;
        }
        else
        {
            ret[0] = i;
        }
    }
    for (int i = 1; i <= nums.size(); i++)
    {
        s.insert(i);
        if (s.size() > len)
        {
            ret[1] = i;
            break;
        }
    }
    return ret;
}

//排序
vector<int> findErrorNums_II(vector<int> &nums)
{
    vector<int> ret(2);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != (i + 1))
        {
            ret[0] = i;
            ret[1] = i + 1;
        }
    }
    return ret;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    vector<int> nums = {1, 2, 2, 4};

    //function
    Timer t;
    auto ret = findErrorNums_II(nums);
    t.printElapsed();
    Print1DMatrix(ret);

    return 0;
}