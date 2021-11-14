/*描述
有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？

本题有多组数据。

输入描述：
输入int型表示month

输出描述：
输出兔子总数int型

示例1
输入：
9
输出：
34
*/
/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int i = 0;
    int m = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    if ((n == 1) || (n == 2))
    {
        printf("1\n");
    }
    int *a = (int *)(malloc(sizeof(int) * n));
    a[0] = 1;
    a[1] = 1;
    for (i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    printf("%d\n", a[n - 1]);

    if ((m == 1) || (m == 2))
    {
        printf("1\n");
        return 0;
    }
    int *b = (int *)(malloc(sizeof(int) * m));
    b[0] = 1;
    b[1] = 1;
    for (i = 2; i < m; i++)
    {
        b[i] = b[i - 1] + b[i - 2];
    }
    printf("%d\n", b[m - 1]);

    free(a);
    free(b);
    return 0;
}*/
//错误分析：应该改成可以无限输入的形式。

/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int i = 0;
    while (scanf("%d", &n) != EOF)
    {
        if ((n == 1) || (n == 2))
        {
            printf("1\n");
        }
        int *a = (int *)(malloc(sizeof(int) * n));
        a[0] = 1;
        a[1] = 1;
        for (i = 2; i < n; i++)
        {
            a[i] = a[i - 1] + a[i - 2];
        }
        printf("%d\n", a[n - 1]);
        free(a);
    }
    return 0;
}
*/
//不足分析：占用内存太大。

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int i = 0;
    int a[3];
    while (scanf("%d", &n) != EOF)
    {
        if ((n == 1) || (n == 2))
        {
            printf("1\n");
        }
        // int *a = (int *)(malloc(sizeof(int) * n));
        a[0] = 1;
        a[1] = 1;
        for (i = 2; i < n; i++)
        {
            a[2] = a[1] + a[0];
            a[0] = a[1];
            a[1] = a[2];
        }
        printf("%d\n", a[2]);
    }
    return 0;
}