/*描述
接受一个只包含小写字母的字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）

输入描述：
输入一行，为一个只包含小写字母的字符串。

输出描述：
输出该字符串反转后的字符串。

示例1
输入：
abcd
输出：
dcba
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
#define MAX_LEN 1000
    char str[MAX_LEN] = {0};
    int i = 0;
    while (scanf("%s", str) != EOF)
    {
        for (i = strlen(str) - 1; i >= 0; i--)
        {
            printf("%c", str[i]);
        }
    }
    return 0;
}