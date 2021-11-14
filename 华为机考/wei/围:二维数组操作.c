#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = {1, 1, 2, 3, 3, 4, 5, 6, 7, 7, 8, 9, 9, 9, 9, 9, 10, 10, 11, 12, 13, 14};

    int left = 0;
    int right = sizeof(a) / sizeof(int) - 1;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (a[mid] >= 9)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    printf("%d\n", left);

    int left_1 = 0;
    int right_1 = sizeof(a) / sizeof(int) - 1;

    while (left_1 < right_1)
    {
        int mid_1 = (left_1 + right_1 + 1) / 2;
        if (a[mid_1] <= 9)
        {
            left_1 = mid_1;
        }
        else
        {
            right_1 = mid_1 - 1;
        }
    }
    printf("%d\n", left_1);
    return 0;
}