/*
239. 滑动窗口最大值
https://leetcode-cn.com/problems/sliding-window-maximum/
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：

输入：nums = [1], k = 1
输出：[1]
示例 3：

输入：nums = [1,-1], k = 1
输出：[1,-1]
示例 4：

输入：nums = [9,11], k = 2
输出：[11]
示例 5：

输入：nums = [4,-2], k = 2
输出：[4]
*/
#include "common.h"

//构造一个单调递减的队列，队列头永远是最大的数(注意需要是双端队列deque)
//pop的时候如果是最大的数，就pop，push的时候，把按照从大到小的顺序插入
//单调队列可以由优先队列简单的实现
class DecreaseQueue
{
public:
    deque<int> decreaseQueue;
    void push(int val)
    {
        while (!decreaseQueue.empty() && val > decreaseQueue.back())
        {
            decreaseQueue.pop_back();
        }
        decreaseQueue.push_back(val);
    }

    void pop(int val)
    {
        if (!decreaseQueue.empty() && val == decreaseQueue.front())
        {
            decreaseQueue.pop_front();
        }
    }

    int front() const
    {
        return decreaseQueue.front();
    }

    void print()
    {
        Print1DMatrix(decreaseQueue);
    }
};

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    DecreaseQueue que;
    vector<int> ret;
    for (int i = 0; i < k; ++i)
    {
        que.push(nums[i]);
    }
    ret.push_back(que.front());
    for (int i = k; i < nums.size(); ++i)
    {
        que.push(nums[i]);
        que.pop(nums[i - k]);
        ret.push_back(que.front());
        // que.print();
    }
    return ret;
}

vector<int> maxSlidingWindow_II(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < k; ++i)
    {
        q.emplace(nums[i], i);
    }
    vector<int> ans = {q.top().first};
    for (int i = k; i < n; ++i)
    {
        q.emplace(nums[i], i);
        while (q.top().second <= i - k)
        {
            q.pop();
        }
        ans.push_back(q.top().first);
    }
    return ans;
}

int main()
{
    //input init
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    //function
    Timer t;
    vector<int> ret;

    ret = maxSlidingWindow(nums, k);
    t.printElapsed();
    ret = maxSlidingWindow_II(nums, k);
    t.printElapsed();

    //print log
    PrintTitle(__FILE__);
    cout << "结果: " << endl;
    Print1DMatrix(ret);
    return 0;
}