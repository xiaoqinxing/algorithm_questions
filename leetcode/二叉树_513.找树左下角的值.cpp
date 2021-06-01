/*
513. 找树左下角的值
https://leetcode-cn.com/problems/find-bottom-left-tree-value/
给定一个二叉树，在树的最后一行找到最左边的值。

示例 1:

输入:

    2
   / \
  1   3

输出:
1
 

示例 2:

输入:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

输出:
7
 

注意: 您可以假设树（即给定的根节点）不为 NULL。
*/
#include "common.h"
#include "tree.h"
#include "timer.h"

//BFS
int findBottomLeftValue(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    int len = 0;
    TreeNode *tmp;
    int left = 0;
    while (!q.empty())
    {
        len = q.size();
        for (int i = 0; i < len; ++i)
        {
            tmp = q.front();
            if (i == 0)
            {
                left = tmp->val;
            }
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
            q.pop();
        }
    }
    return left;
}

//递归的方法
//如果需要遍历整颗树，递归函数就不能有返回值。如果需要遍历某一条固定路线，递归函数就一定要有返回值！
void backtracking(TreeNode *root, int depth, int &maxleftvalue, int &maxlen)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        if (depth > maxlen)
        {
            maxlen = depth;
            maxleftvalue = root->val;
        }
        return;
    }

    depth++;
    if (root->left)
        backtracking(root->left, depth, maxleftvalue, maxlen);
    if (root->right)
        backtracking(root->right, depth, maxleftvalue, maxlen);
    depth--;
}
//递归
int findBottomLeftValue_II(TreeNode *root)
{
    int ret = 0;
    int maxlen = 0;
    backtracking(root, 1, ret, maxlen);
    return ret;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    TreeTest tree("[1,2,3,4,null,5,6,null,null,7]");
    tree.print();
    //function
    Timer t;
    auto ret = findBottomLeftValue(tree.getroot());
    t.printElapsed();
    PrintVal(ret);

    t.reset();
    ret = findBottomLeftValue_II(tree.getroot());
    t.printElapsed();
    PrintVal(ret);

    return 0;
}