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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ret;
    queue<TreeNode *> bfs;
    if (root != nullptr)
        bfs.push(root);
    int len = 1;
    vector<int> ret_tmp;
    TreeNode *tmp;
    while (!bfs.empty())
    {
        len = bfs.size();
        ret_tmp.clear();
        for (int i = 0; i < len; ++i)
        {
            tmp = bfs.front();
            ret_tmp.push_back(tmp->val);
            if (tmp->left != nullptr)
                bfs.push(tmp->left);
            if (tmp->right != nullptr)
                bfs.push(tmp->right);
            bfs.pop();
        }
        ret.push_back(ret_tmp);
    }
    return ret;
}

int main()
{
    //input init
    int nums = 1;
    TreeNode *root = createTree("[3,9,20,null,null,15,7]");
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

    ret.clear();
    t.reset();
    auto r = levelOrder(root);
    t.printElapsed();
    Print2DMatrix(r);

    cout << "\r\n二叉树结构：" << endl;
    printTree(root);
    destoryTree(root);
    return 0;
}