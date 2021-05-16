#include <iostream>
#include <vector>
using namespace std;
/**
 * 查找下一个有效的值
 * input:
 * @index: 下一个值从index开始查找
 * @sum: 上一次的累加和
 * output: 最后的输出
 * socre[i] = max(score[i-1],score[i-2]+a[i])
 * 分成0~i-1和1~i两个部分
 */
int find_max_score(vector<int> &a)
{
    if (a.size() == 0)
        return 0;
    else if (a.size() == 1)
        return a[0];
    else if (a.size() == 2)
        return max(a[0], a[1]);

    vector<int> score(a.size() - 1, 0), score1(a.size() - 1, 0);

    score[0] = a[0];
    score[1] = max(a[0], a[1]);
    for (int i = 2; i < a.size() - 1; ++i)
    {
        score[i] = max(score[i - 2] + a[i], score[i - 1]);
    }
    score1[0] = a[1];
    score1[1] = max(a[1], a[2]);
    for (int i = 2; i < a.size() - 1; ++i)
    {
        score1[i] = max(score1[i - 1] + a[i + 1], score1[i - 2]);
    }
    return max(score[a.size() - 2], score1[a.size() - 2]);
}
int main()
{
    vector<int> money;
    int input, score;
    while (cin >> input)
    {
        money.push_back(input);
    }
    score = find_max_score(money);
    cout << score << endl;
    return 0;
}