#include <stdio.h>

int main()
{
    float input_value = 0;
    float float_num = 0;
    int output_num = 0;
    int int_num = 0;

    scanf("%f", &input_value);
    int_num = (int)input_value;
    float_num = input_value - (float)int_num;
    if (float_num >= 0.5)
    {
        output_num = int_num + 1;
        printf("%d", output_num);
    }
    else
    {
        output_num = int_num;
        printf("%d", output_num);
    }
    return 0;
}