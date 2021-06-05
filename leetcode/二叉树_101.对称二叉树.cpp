/*
101. 对称二叉树
https://leetcode-cn.com/problems/symmetric-tree/
给定一个二叉树，检查它是否是镜像对称的。

 

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
*/
#include "common.h"
#include "test_tree.h"
#include "timer.h"
bool isReverseSame(vector<TreeNode *> &vec)
{
    int i = 0;
    int j = vec.size() - 1;
    while (i < j)
    {
        if (vec[i] == nullptr || vec[j] == nullptr)
        {
            if (vec[i] != vec[j])
            {
                return false;
            }
        }
        else if (vec[i]->val != vec[j]->val)
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
//使用数组
bool isSymmetric(TreeNode *root)
{
    vector<TreeNode *> q;
    // vector<int> vec;
    if (root != nullptr)
        q.push_back(root);
    TreeNode *tmp;
    int len = 0;
    while (q.size())
    {
        len = q.size();
        // vec.clear();
        for (int i = 0; i < len; ++i)
        {
            tmp = q[0];
            if (tmp != nullptr)
            {
                // vec.push_back(tmp->val);
                // if (tmp->left != nullptr)
                q.push_back(tmp->left);
                // if (tmp->right != nullptr)
                q.push_back(tmp->right);
            }
            q.erase(q.begin());
        }
        if (!isReverseSame(q))
        {
            return false;
        }
    }
    return true;
}

bool compare(TreeNode *left, TreeNode *right)
{
    // 首先排除空节点的情况
    if (left == NULL && right != NULL)
        return false;
    else if (left != NULL && right == NULL)
        return false;
    else if (left == NULL && right == NULL)
        return true;
    // 排除了空节点，再排除数值不相同的情况
    else if (left->val != right->val)
        return false;

    // 此时就是：左右节点都不为空，且数值相同的情况
    // 此时才做递归，做下一层的判断
    bool outside = compare(left->left, right->right); // 左子树：左、 右子树：右
    bool inside = compare(left->right, right->left);  // 左子树：右、 右子树：左
    bool isSame = outside && inside;                  // 左子树：中、 右子树：中 （逻辑处理）
    return isSame;
}
//使用递归
bool isSymmetric_II(TreeNode *root)
{
    if (root == NULL)
        return true;
    return compare(root->left, root->right);
}

//使用队列
bool isSymmetric_III(TreeNode *root)
{
    if (root == NULL)
        return true;
    queue<TreeNode *> que;
    que.push(root->left);  // 将左子树头结点加入队列
    que.push(root->right); // 将右子树头结点加入队列
    while (!que.empty())
    { // 接下来就要判断这这两个树是否相互翻转
        TreeNode *leftNode = que.front();
        que.pop();
        TreeNode *rightNode = que.front();
        que.pop();
        if (!leftNode && !rightNode)
        { // 左节点为空、右节点为空，此时说明是对称的
            continue;
        }

        // 左右一个节点不为空，或者都不为空但数值不相同，返回false
        if ((!leftNode || !rightNode || (leftNode->val != rightNode->val)))
        {
            return false;
        }
        que.push(leftNode->left);   // 加入左节点左孩子
        que.push(rightNode->right); // 加入右节点右孩子
        que.push(leftNode->right);  // 加入左节点右孩子
        que.push(rightNode->left);  // 加入右节点左孩子
    }
    return true;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    TreeNode *root = createTree("[1,2,2,3,null,null,3,1,2,2,1]");

    //方法一
    Timer t;
    auto ret = isSymmetric(root);
    t.printElapsed();
    PrintVal(ret);

    t.reset();
    ret = isSymmetric_II(root);
    t.printElapsed();
    PrintVal(ret);

    t.reset();
    ret = isSymmetric_III(root);
    t.printElapsed();
    PrintVal(ret);

    auto vec = traversalTree(root);
    Print2DMatrix(vec);
    printTree(root);
    destoryTree(root);
    return 0;
}