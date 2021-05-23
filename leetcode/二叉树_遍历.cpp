/*

*/
#include "common.h"
#include "tree.h"
#include "timer.h"

void preorderTraversal(TreeNode *root, vector<int> &ret)
{
    if (root == nullptr)
    {
        return;
    }
    ret.push_back(root->val);
    preorderTraversal(root->left, ret);
    preorderTraversal(root->right, ret);
}

void postorderTraversal(TreeNode *root, vector<int> &ret)
{
    if (root == nullptr)
    {
        return;
    }

    postorderTraversal(root->left, ret);
    postorderTraversal(root->right, ret);
    ret.push_back(root->val);
}

void inorderTraversal(TreeNode *root, vector<int> &ret)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left, ret);
    ret.push_back(root->val);
    inorderTraversal(root->right, ret);
}

int main()
{
    //input init
    int nums = 1;
    TreeNode *root = createTree("[1,null,2,3]");
    vector<int> ret;

    //print log
    PrintTitle(__FILE__);

    //function
    Timer t;
    preorderTraversal(root, ret);
    t.printElapsed();
    Print1DMatrix(ret);

    ret.clear();
    t.reset();
    postorderTraversal(root, ret);
    t.printElapsed();
    Print1DMatrix(ret);

    ret.clear();
    t.reset();
    inorderTraversal(root, ret);
    t.printElapsed();
    Print1DMatrix(ret);

    printTree(root);
    destoryTree(root);
    return 0;
}