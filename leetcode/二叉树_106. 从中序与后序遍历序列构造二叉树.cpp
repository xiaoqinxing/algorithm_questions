/*
106. 从中序与后序遍历序列构造二叉树
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*/
#include "common.h"
#include "test_tree.h"
#include "timer.h"

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    TreeNode *root;
    int len = inorder.size();
    int rootIndex = 0;
    if (len >= 1)
    {
        root = new TreeNode(postorder[len - 1]);
    }
    else
    {
        return nullptr;
    }
    map<int, int> inorderIndex;
    for (int i = 0; i < len; ++i)
    {
        inorderIndex[inorder[i]] = i;
    }
    rootIndex = inorderIndex[root->val];

    int tmpindex = 0;
    TreeNode *current = root;
    TreeNode *preroot = root;
    for (int i = len - 2; i >= 0; --i)
    {

        tmpindex = inorderIndex[postorder[i]];
        if (rootIndex < tmpindex)
        {
            current->right = new TreeNode(postorder[i]);
            preroot = current;
            current = current->right;
        }
        else
        {
            preroot->left = new TreeNode(postorder[i]);
            current = preroot->left;
        }
        rootIndex = tmpindex;
    }
    return root;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    //function
    Timer t;
    auto ret = buildTree(inorder, postorder);
    t.printElapsed();
    printTree(ret);
    destoryTree(ret);

    return 0;
}