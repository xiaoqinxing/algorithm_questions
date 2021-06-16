/*

*/
#include "common.h"
#include "test_tree.h"
#include "test_list.h"
#include "timer.h"

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    int left = root1 == nullptr ? 0 : root1->val;
    int right = root2 == nullptr ? 0 : root2->right;
    if (root1 != nullptr && root2 != nullptr)
    {
        mergeTrees(root1->left, root2->left);
        mergeTrees(root1->right, root2->right);
    }
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    TreeNode tree1 = createTree("[1,3,2,5]");
    TreeNode tree2 = createTree("[2,1,3,null,4,null,7]");

    //function
    Timer t;
    auto ret = mergeTrees(root1, root2);
    t.printElapsed();
    PrintVal(ret);

    return 0;
}