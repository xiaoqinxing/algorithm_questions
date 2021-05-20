/*

*/
#include "common.h"

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> frequentMap;
    vector<int> ret;
    for (int i : nums)
    {
        frequentMap[i]++;
    }
    vector<pair<int, int>> vec_nums;
    for (const auto &i : frequentMap)
    {
        vec_nums.push_back(i);
    }
    sort(vec_nums.begin(), vec_nums.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    });
    for (int i = 0; i < k; ++i)
    {
        ret.push_back(vec_nums[i].first);
    }
    return ret;
}

//注意优先级队列比较函数一定要写成class模式
//注意优先级队列和普通的排序判断是反的，左大于右就是小堆顶，右大于左就是大堆顶。
class cmp
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second < b.second;
    }
};

vector<int> topKFrequent_II(vector<int> &nums, int k)
{
    unordered_map<int, int> frequentMap;
    vector<int> ret;
    for (int i : nums)
    {
        frequentMap[i]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> vec_nums;
    for (const auto &i : frequentMap)
    {
        vec_nums.push(i);
    }

    for (int i = 0; i < k; ++i)
    {
        ret.push_back(vec_nums.top().first);
        vec_nums.pop();
    }
    return ret;
}

int main()
{
    //print log
    PrintTitle(__FILE__);

    //input init
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    //function
    Timer t;
    vector<int> ret;
    ret = topKFrequent(nums, k);
    t.printElapsed();
    cout << "结果: " << endl;
    Print1DMatrix(ret);
    t.reset();
    ret = topKFrequent_II(nums, k);
    t.printElapsed();

    cout << "结果: " << endl;
    Print1DMatrix(ret);
    return 0;
}