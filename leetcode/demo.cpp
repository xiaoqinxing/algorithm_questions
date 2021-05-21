/*

*/
#include "common.h"
#include "tree.h"
#include "timer.h"

int function(int nums)
{
    return nums;
}

int main()
{
    //input init
    int nums = 1;

    //function
    Timer t;
    auto ret = function(nums);
    t.printElapsed();

    //print log
    PrintTitle(__FILE__);
    cout << "结果: " << endl;
    cout << ret << endl;
    return 0;
}