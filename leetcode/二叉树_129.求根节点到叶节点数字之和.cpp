/*
129. 求根节点到叶节点数字之和
给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。

叶节点 是指没有子节点的节点。
*/
#include "common.h"
#include "test_tree.h"
#include "test_list.h"
#include "timer.h"

// int sumNumbers(TreeNode *root)
// {
//     int left = 0, right = 0;
//     int tmp;
//     int level;
//     if (root->left)
//     {
//         left = sumNumbers(root->left);
//         tmp = left;
//         level = 1;
//         while (tmp)
//         {
//             level *= 10;
//             tmp /= 10;
//         }
//         left += root->val * level;
//     }

//     if (root->right)
//     {
//         right = sumNumbers(root->right);
//         tmp = right;
//         level = 1;
//         while (tmp)
//         {
//             level *= 10;
//             tmp /= 10;
//         }
//         right += root->val * level;
//     }

//     if (left + right == 0)
//     {
//         return root->val;
//     }

//     return left + right;
// }

void backtracking(TreeNode *root, int &ret, int path)
{
    if (!root->left && !root->right)
    {
        ret += path * 10 + root->val;
        return;
    }
    if (root->left)
    {
        backtracking(root->left, ret, path * 10 + root->val);
    }
    if (root->right)
    {
        backtracking(root->right, ret, path * 10 + root->val);
    }
}

int sumNumbers_II(TreeNode *root)
{
    int ret = 0;
    backtracking(root, ret, 0);
    return ret;
}

int dfs(TreeNode *root, int prevSum)
{
    if (root == nullptr)
    {
        return 0;
    }
    int sum = prevSum * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr)
    {
        return sum;
    }
    else
    {
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
}
int sumNumbers_III(TreeNode *root)
{
    return dfs(root, 0);
}

int sumNumbers(TreeNode *root)
{
    queue<TreeNode *> q;
    queue<int> presum;
    q.push(root);
    presum.push(0);
    int len;
    int level = 1;
    int ret = 0;
    int pre = 0;
    while (!q.empty())
    {
        len = q.size();
        for (int i = 0; i < len; i++)
        {
            TreeNode *tmp = q.front();
            int pre = presum.front();
            pre = pre * 10 + tmp->val;
            if (!tmp->left && !tmp->right)
            {
                ret += pre;
            }
            q.pop();
            presum.pop();
            if (tmp->left)
            {
                q.push(tmp->left);
                presum.push(pre);
            }

            if (tmp->right)
            {
                q.push(tmp->right);
                presum.push(pre);
            }
        }
        // level *= 10;
    }
    return ret;
}
int main()
{
    PrintTitle(__FILE__);

    // TreeNode *root = createTree("[1,2,3]");
    TreeNode *root = createTree("[4,9,0,5,1]");

    //function
    Timer t;
    auto ret = sumNumbers(root);
    t.printElapsed();
    PrintVal(ret);
    printTree(root);
    destoryTree(root);

    return 0;
}