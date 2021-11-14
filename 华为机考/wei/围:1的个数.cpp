/*
描述
输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。

输入描述：
输入一个整数（int类型）

输出描述：
这个数转换成2进制后，输出1的个数

示例1
输入：5
输出：2
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int in_num = 0;
    int i = 0;
    scanf("%d", &in_num);
    if (in_num == 0)
    {
        i = 0;
    }
    else
    {
        while (in_num != 0)
        {
            if (in_num & 1 == 1)
            {
                i++;
            }
            in_num = in_num >> 1;
        }
    }
    printf("%d", i);
    return 0;
}