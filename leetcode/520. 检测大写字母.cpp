/*
520. 检测大写字母
我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如 "USA" 。
单词中所有字母都不是大写，比如 "leetcode" 。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。

 

示例 1：

输入：word = "USA"
输出：true
示例 2：

输入：word = "FlaG"
输出：false
 

提示：

1 <= word.length <= 100
word 由小写和大写英文字母组成
*/
#include "common.h"
#include "test_tree.h"
#include "test_list.h"
#include "timer.h"

bool detectCapitalUse(string word)
{
    int len = word.size();
    if (word.size() >= 2)
    {
        if (islower(word[0]) && isupper(word[1]))
        {
            return false;
        }
    }
    for (int i = 2; i < len; i++)
    {
        if (isupper(word[i]) ^ isupper(word[1]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    string a = "FlaG";

    //function
    Timer t;
    auto ret = detectCapitalUse(a);
    t.printElapsed();
    PrintVal(ret);

    return 0;
}