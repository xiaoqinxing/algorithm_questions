/*
113. 路径总和 II
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

 

示例 1：


输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
示例 2：


输入：root = [1,2,3], targetSum = 5
输出：[]
示例 3：

输入：root = [1,2], targetSum = 0
输出：[]
 

提示：

树中节点总数在范围 [0, 5000] 内
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
*/
#include "common.h"
#include "test_tree.h"
#include "timer.h"

vector<vector<int>> ret;
int sum = 0;
vector<int> path;
void backtracking(TreeNode *root, int targetSum)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right && root->val == targetSum)
    {
        path.push_back(root->val);
        ret.push_back(path);
        path.pop_back();
        return;
    }

    path.push_back(root->val);
    backtracking(root->left, targetSum - root->val);
    backtracking(root->right, targetSum - root->val);
    path.pop_back();
    return;
}

//最终版本！
void backtracking_II(TreeNode *root, int targetSum)
{
    if (!root)
    {
        return;
    }

    path.push_back(root->val);
    targetSum -= root->val;
    if (!root->left && !root->right && 0 == targetSum)
    {
        ret.push_back(path);
        //return; //回溯之前不能return!!!!!
    }

    backtracking_II(root->left, targetSum);
    backtracking_II(root->right, targetSum);
    path.pop_back();
    return;
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    if (!root)
    {
        return vector<vector<int>>();
    }
    if (!root->left && !root->right)
    {
        if (sum + root->val == targetSum)
        {
            path.push_back(root->val);
            ret.push_back(path);
            path.pop_back();
        }
    }
    sum += root->val;
    path.push_back(root->val);
    if (root->left)
    {
        pathSum(root->left, targetSum);
    }

    if (root->right)
    {
        pathSum(root->right, targetSum);
    }
    sum -= root->val;
    path.pop_back();

    return ret;
}

vector<vector<int>> pathSum_II(TreeNode *root, int targetSum)
{
    ret.clear();
    backtracking(root, targetSum);
    return ret;
}

vector<vector<int>> pathSum_III(TreeNode *root, int targetSum)
{
    ret.clear();
    backtracking_II(root, targetSum);
    return ret;
}

int main()
{
    PrintTitle(__FILE__);
    //input init
    TreeTest tree("[5,4,8,11,null,13,4,7,2,null,null,5,1]");
    tree.print();
    int target = 22;

    //function
    Timer t;
    auto ret = pathSum(tree.getroot(), target);
    t.printElapsed();
    Print2DMatrix(ret);

    t.reset();
    ret = pathSum_II(tree.getroot(), target);
    t.printElapsed();
    Print2DMatrix(ret);

    t.reset();
    ret = pathSum_III(tree.getroot(), target);
    t.printElapsed();
    Print2DMatrix(ret);

    return 0;
}