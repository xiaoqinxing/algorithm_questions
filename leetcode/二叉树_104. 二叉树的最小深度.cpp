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
    if (root->left == nullptr && root->right == nullptr)
    {
        depth = min(depth, path);
        return;
    }
    if (root->left != nullptr)
        backtracking(root->left, depth, path + 1);
    if (root->right != nullptr)
        backtracking(root->right, depth, path + 1);
}
int minDepth(TreeNode *root)
{
    int depth = INT32_MAX;
    if (root != nullptr)
    {
        backtracking(root, depth, 1);
        return depth;
    }
    else
        return 0;
}

//递归 比较递归返回之后的结果,因此是后序遍历
int minDepth_II(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftDepth = minDepth_II(root->left);
    int rightDepth = minDepth_II(root->right);
    // 当一个左子树为空，右不为空，这时并不是最低点
    if (root->left == NULL && root->right != NULL)
    {
        return 1 + rightDepth;
    }
    // 当一个右子树为空，左不为空，这时并不是最低点
    if (root->left != NULL && root->right == NULL)
    {
        return 1 + leftDepth;
    }
    return min(leftDepth, rightDepth) + 1;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    // TreeNode *root = createTree("[3,9,20,null,null,15,7]");
    TreeNode *root = createTree("[2,null,3,null,4,null,5,null,6]");

    //function
    Timer t;
    t.reset();
    auto ret = minDepth_II(root);
    t.printElapsed();
    PrintVal(ret);

    t.reset();
    ret = minDepth(root);
    t.printElapsed();
    PrintVal(ret);

    destoryTree(root);
    return 0;
}