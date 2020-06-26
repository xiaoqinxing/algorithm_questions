#include <iostream>
#include <string>
using namespace std;
/**
 * 将字符串（扑克牌）转成int类型，方便计算
 */
int toint(string &tmp)
{
    if (tmp == "J")
        return 11;
    else if (tmp == "Q")
        return 12;
    else if (tmp == "K")
        return 13;
    else if (tmp == "A")
        return 14;
    else if (tmp == "2")
        return 15;
    else if (tmp == "joker")
        return 16;
    else if (tmp == "JOKER")
        return 17;
    else
        return stoi(tmp);
}
/**
 * 对字符串进行分割，返回分割后的数量。array是返回的数组。
 */
int split(string str, int *array)
{
    int index = 0;
    string tmp;
    int i = 0;
    while (index != -1)
    {
        index = str.find(' ');
        if (index != -1)
        {
            tmp = str.substr(0, index);
            str = str.substr(index + 1);
            array[i] = toint(tmp);
            ++i;
        }
        else
        {
            array[i] = toint(str);
            ++i;
        }
    }
    return i;
}
/**
 * 对牌进行分类
 * 返回的值是类型，子，对子，三子分别返回123。炸弹返回5，顺子返回4，王炸返回6.
 */
int type(int *array, int num)
{
    if (num == 2 && array[0] > 15 && array[1] > 15)
        return 6;
    else if (num == 4)
        return 5;
    else if (num == 5)
        return 4;
    else
        return num;
}
int main()
{
    string left_str, right_str;
    int left_vec[5], right_vec[5];
    int left_num, right_num, left_type, right_type;
    while (getline(cin, right_str))
    {
        left_str = right_str.substr(0, right_str.find('-'));
        right_str = right_str.substr(right_str.find('-') + 1);

        left_num = split(left_str, left_vec);
        right_num = split(right_str, right_vec);

        left_type = type(left_vec, left_num);
        right_type = type(right_vec, right_num);
        if (left_type == right_type)
        {
            if (left_vec[0] < right_vec[0])
                cout << right_str << endl;
            else
                cout << left_str << endl;
        }
        else
        {
            if (left_type >= 5)
            {
                if (right_type >= 5)
                {
                    if (left_vec[0] < right_vec[0])
                        cout << right_str << endl;
                    else
                        cout << left_str << endl;
                }
                else
                    cout << left_str << endl;
            }
            else
            {
                if (right_type >= 5)
                    cout << right_str << endl;
                else
                    cout << "ERROR" << endl;
            }
        }
    }
    return 0;
}
