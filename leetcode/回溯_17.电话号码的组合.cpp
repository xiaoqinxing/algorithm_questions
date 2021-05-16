/*
17. 电话号码的字母组合
https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。


示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]
*/

#include "common.h"

void PrintTitle(void)
{
    string path(__FILE__);
    auto path_suffix = path.find_last_of('.');
    auto path_presuffix = path.find_last_of('/') + 1;
    cout << "[题目：" << path.substr(path_presuffix, path_suffix - path_presuffix) << "]" << endl;
}

vector<vector<char>> num2str(
    {{'a', 'b', 'c'},
     {'d', 'e', 'f'},
     {'g', 'h', 'i'},
     {'j', 'k', 'l'},
     {'m', 'n', 'o'},
     {'p', 'q', 'r', 's'},
     {'t', 'u', 'v'},
     {'w', 'x', 'y', 'z'}});

void backtracking(int startIndex, string &inputStr, string &path, vector<string> &ret)
{
    if (startIndex == inputStr.size())
    {
        ret.push_back(path);
        return;
    }

    for (char i : num2str[inputStr[startIndex] - '2'])
    {
        path.push_back(i);
        backtracking(startIndex + 1, inputStr, path, ret);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ret;
    string path;
    if (digits.size() == 0)
    {
        return vector<string>();
    }
    backtracking(0, digits, path, ret);
    return ret;
}

int main()
{
    //input init
    string nums = "";

    //function
    auto start = std::chrono::steady_clock::now();
    auto ret = letterCombinations(nums);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    //print log
    PrintTitle();
    cout << "结果: " << endl;
    PrintContainer(ret);
    cout << "耗时: " << elapsed_seconds.count() << "s" << endl;
    return 0;
}