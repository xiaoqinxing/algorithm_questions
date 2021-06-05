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
    //input init
    int nums = 1;

    //function
    Timer t;
    auto ret = function(nums);
    t.printElapsed();
    PrintVal(ret);

    return 0;
}