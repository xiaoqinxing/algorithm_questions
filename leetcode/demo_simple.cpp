/*

*/
#include "common.h"
#include "test_tree.h"
#include "test_list.h"
#include "timer.h"

int function(int nums)
{
    return nums;
}

int main()
{
    PrintTitle(__FILE__);
    INIT(int, int);
    TEST(function, 1, PrintVal, PrintVal);
    return 0;
}