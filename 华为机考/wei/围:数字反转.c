/*描述
输入一个整数，将这个整数以字符串的形式逆序输出
程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001


输入描述：
输入一个int整数

输出描述：
将这个整数以字符串的形式逆序输出

示例1
输入：
1516000
输出：
0006151
*/

/*方法一：
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;
    int last_num = 0;
    int i, j = 0;
    while (scanf("%d", &num) != EOF)
    {
        while (num != 0)
        {
            last_num = num % 10;
            num = num / 10;
            printf("%d", last_num);
        }
    }
    return 0;
}
*/

/*
方法二：先将输入的数字转化为字符串然后输出
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int num = 0;
    char a[10] = {0};
    int i = 0;

    while (scanf("%d", &num) != EOF)
    {
        sprintf(a, "%d", num);
        for (i = strlen(a) - 1; i >= 0; i--)
        {
            printf("%c", a[i]);
        }
    }

    return 0;
}
*/

/*方法三：栈 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
#define MAX_LEN 10

    char in_num[MAX_LEN] = {0};
    int i = 0;
    char stack[MAX_LEN + 1] = {0};
    int top = 0;
    scanf("%s", in_num);

    for (i = 0; i < strlen(in_num); i++)
    {
        stack[top] = in_num[i];
        top++;
    }
    top--;
    while (top >= 0)
    {
        printf("%c", stack[top]);
        top--;
    }
    return 0;
}
