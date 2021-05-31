/*
404. 左叶子之和
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
*/
#include "common.h"
#include "tree.h"
#include "timer.h"

//回溯
void backtracking(TreeNode *root, int &sum)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
    {
        sum += root->left->val;
    }
    backtracking(root->left, sum);
    backtracking(root->right, sum);
}
int sumOfLeftLeaves(TreeNode *root)
{
    int sum = 0;
    backtracking(root, sum);
    return sum;
}

//递归
int sumOfLeftLeaves_II(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftvalue = sumOfLeftLeaves_II(root->left);
    int rightvalue = sumOfLeftLeaves_II(root->right);
    int midvalue = 0;
    if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
    {
        midvalue = root->left->val;
    }
    return leftvalue + rightvalue + midvalue;
}

int main()
{
    PrintTitle(__FILE__);

    TreeTest tree("[3,9,20,null,null,15,7]");
    tree.print();

    Timer t;
    auto ret = sumOfLeftLeaves(tree.getroot());
    t.printElapsed();
    PrintVal(ret);
    return 0;
}