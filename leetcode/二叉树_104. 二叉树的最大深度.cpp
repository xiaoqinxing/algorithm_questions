/*
104. 二叉树的最大深度
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
*/
#include "common.h"
#include "test_tree.h"
#include "timer.h"

//回溯
void backtracking(TreeNode *root, int &depth, int path)
{
    if (root == nullptr)
    {
        depth = max(depth, path);
        return;
    }
    backtracking(root->left, depth, path + 1);
    backtracking(root->right, depth, path + 1);
}
int maxDepth(TreeNode *root)
{
    int depth = 0;
    backtracking(root, depth, 0);
    return depth;
}

//递归
int maxDepth_II(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftDepth = maxDepth_II(root->left);
    int rightDepth = maxDepth_II(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    TreeNode *root = createTree("[3,9,20,null,null,15,7]");

    //function
    Timer t;
    auto ret = maxDepth(root);
    t.printElapsed();
    PrintVal(ret);

    t.reset();
    ret = maxDepth_II(root);
    t.printElapsed();
    PrintVal(ret);

    destoryTree(root);
    return 0;
}