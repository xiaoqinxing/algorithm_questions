/*
110. 平衡二叉树
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

 

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：true
示例 2：


输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
示例 3：

输入：root = []
输出：true
 

提示：

树中的节点数在范围 [0, 5000] 内
-104 <= Node.val <= 104
*/
#include "common.h"
#include "tree.h"
#include "timer.h"
int result = 0;
int getDepth(TreeNode *root)
{
    // result = max(depth, result);
    if (root == nullptr)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left + right) + 1;
}
int isBalanced(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = getDepth(root->left);
    int right = getDepth(root->right);
    if (abs(left - right) > 1)
        return false;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    TreeNode *root = createTree("[1,2,3,4,5,6]");

    //function
    Timer t;
    auto ret = isBalanced(root);
    t.printElapsed();
    PrintVal(ret);

    destoryTree(root);
    return 0;
}