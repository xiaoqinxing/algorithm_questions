/*
描述
输入整型数组和排序标识，对其元素按照升序或降序进行排序

输入描述：
第一行输入数组元素个数
第二行输入待排序的数组，每个数用空格隔开
第三行输入一个整数0或1。0代表升序排序，1代表降序排序

输出描述：
输出排好序的数字

示例1
输入：
8
1 2 4 9 3 55 64 25
0
输出：
1 2 3 4 9 25 55 64
示例2
输入：
5
1 2 3 4 5
1
输出：
5 4 3 2 1
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int comp_0(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int comp_1(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main()
{
    int num = 0;
    int order = 0;
    scanf("%d", &num);
    if (num <= 0)
    {
        return -1;
    }
    int *val = (int *)(malloc(sizeof(int) * num));
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &val[i]);
    }
    scanf("%d", &order);
    if (order == 0)
    {
        qsort(val, num, sizeof(int), comp_0);
    }
    else if (order == 1)
    {
        qsort(val, num, sizeof(int), comp_1);
    }
    else
    {
        return -1;
    }
    for (int i = 0; i < num; i++)
    {
        printf("%d ", val[i]);
    }
    if (val != NULL)
    {
        free(val);
    }
    return 0;
}
