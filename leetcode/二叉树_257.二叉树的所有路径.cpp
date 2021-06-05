/*
257. 二叉树的所有路径
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
*/
#include "common.h"
#include "test_tree.h"
#include "timer.h"

void backtracking(TreeNode *root, vector<string> &ret, vector<int> &path)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        string tmp;
        for (int i = 0; i < path.size(); ++i)
        {
            tmp.append(to_string(path[i]) + "->");
        }
        tmp.append(to_string(root->val));
        ret.push_back(tmp);
        return;
    }
    path.push_back(root->val);
    backtracking(root->left, ret, path);
    backtracking(root->right, ret, path);
    path.pop_back();
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ret;
    vector<int> path;
    backtracking(root, ret, path);
    return ret;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    TreeNode *root = createTree("[1,2,3,null,5]");

    //function
    Timer t;
    auto ret = binaryTreePaths(root);
    t.printElapsed();
    Print1DMatrix(ret);

    printTree(root);
    destoryTree(root);
    return 0;
}