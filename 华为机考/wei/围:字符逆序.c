/*
描述
将一个字符串str的内容颠倒过来，并输出。str的长度不超过100个字符。


输入描述：
输入一个字符串，可以有空格

输出描述：
输出逆序的字符串

示例1
输入：
I am a student
输出：
tneduts a ma I
*/

/*注意fgets读入的数据中包含有最后的 '\0' ，也占了一个字节。
所以计算str_len的时候是算的str_len = strlen(input_str) - 1;

fgets的用法是：char *fgets(char *s, int size, FILE *stream); *stream在此处应为stdin。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
#define MAX_LEN 100
    char str[MAX_LEN] = {0};
    int i = 0;
    int len = 0;

    fgets(str, MAX_LEN, stdin);

    len = strlen(str) - 1;

    for (i = len - 1; i >= 0; i--)
    /*如果这里i的起始数值是len的话，会出现错误，即输出会多出一个换行符，但是实际要求的输出是不要这个换行符的，所以要减1*/
    {
        printf("%c", str[i]);
    }
    return 0;
}