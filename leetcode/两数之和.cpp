#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>
using namespace std;

template <class T>
void Print(T begin, T end)
{
    for (; begin != end; begin++)
    {
        cout << *begin << " ";
    }
    cout << endl;
}
vector<int> twoSum1(vector<int> &nums, int target)
{
    vector<int> ret(2);
    vector<int>::iterator it2, it1;
    for (it1 = nums.begin(); it1 != nums.end(); ++it1)
    {
        it2 = find(it1 + 1, nums.end(), target - *it1);
        if (it2 != nums.end())
        {
            ret[0] = distance(nums.begin(), it1);
            ret[1] = distance(nums.begin(), it2);
            break;
        }
    }
    return ret;
}
vector<int> twoSum2(vector<int> &nums, int target)
{
    vector<int> ret(2);
    map<int, int> nums_map;
    map<int, int>::iterator nums_map_it;
    for (int i = 0; i < nums.size(); ++i)
    {
        nums_map[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        nums_map_it = nums_map.find(target - nums[i]);
        if (nums_map_it != nums_map.end())
        {
            if (i == nums_map_it->second)
                continue;
            ret[0] = i;
            ret[1] = nums_map_it->second;
            break;
        }
    }
    return ret;
}

int main()
{
    int tmp[4] = {3, 2, 4};
    int target = 6;
    vector<int> nums(tmp, tmp + 4);
    vector<int> test(4);
    test = nums;
    Print(test.begin(), test.end());
    cout << "distance: " << distance(nums.begin(), nums.end()) << endl;

    auto start = std::chrono::steady_clock::now();
    vector<int> ret1 = twoSum1(nums, target);
    vector<int> ret2 = twoSum2(nums, target);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << "[题目：]" << endl;
    cout << "结果: " << endl;
    Print(ret1.begin(), ret1.end());
    Print(ret2.begin(), ret2.end());
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}
