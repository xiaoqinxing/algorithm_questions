/*
剑指 Offer 38. 字符串的排列
https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "common.h"
#include "test_tree.h"
#include "test_list.h"
#include "timer.h"

void backtracking(string &s, string &path, vector<int> &used, vector<string> &ret)
{
    if (path.size() == s.size())
    {
        ret.push_back(path);
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (used[i] != 0)
            continue;
        //注意used[i - 1] == 0，说明在同一层使用过，一般这个效率高
        //used[i-1] == 1，说明在同一树枝使用过
        if (i > 0 && s[i] == s[i - 1] && used[i - 1] == 0)
            continue;

        path.push_back(s[i]);
        used[i] = 1;
        backtracking(s, path, used, ret);
        used[i] = 0;
        path.pop_back();
    }
}

vector<string> permutation(string s)
{
    vector<string> ret;
    string path;
    vector<int> used(s.size());
    //去重一定要对元素经行排序，这样我们才方便通过相邻的节点来判断是否重复使用了
    sort(s.begin(), s.end());
    backtracking(s, path, used, ret);
    return ret;
}

int main()
{
    PrintTitle(__FILE__);
    INIT(string, vector<string>);
    TEST(permutation, "abc", PrintVal, Print1DMatrix);
    TEST(permutation, "aab", PrintVal, Print1DMatrix);
    TEST(permutation, "aaab", PrintVal, Print1DMatrix);
    return 0;
}