#ifndef __TEST_H__
#define __TEST_H__
#include "common.h"
#include <sstream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                }).base(),
                input.end());
}

TreeNode *createTree(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

void traversalTree(TreeNode *cur, vector<int> &vec)
{
    if (cur == NULL)
        return;
    vec.push_back(cur->val);        // 中
    traversalTree(cur->left, vec);  // 左
    traversalTree(cur->right, vec); // 右
}

void destoryTree(TreeNode *tree)
{
    if (NULL != tree)
    {
        destoryTree(tree->left);
        destoryTree(tree->right);
        delete tree;
    }
}

int vec_left[100] = {0};
void printTree(TreeNode *root, int ident = 0)
{
    if (ident > 0)
    {
        for (int i = 0; i < ident - 1; ++i)
        {
            printf(vec_left[i] ? "│   " : "    ");
        }
        printf(vec_left[ident - 1] ? "├── " : "└── ");
    }

    if (!root)
    {
        printf("(null)\n");
        return;
    }

    printf("%d\n", root->val);
    if (!root->left && !root->right)
    {
        return;
    }

    vec_left[ident] = 1;
    printTree(root->left, ident + 1);
    vec_left[ident] = 0;
    printTree(root->right, ident + 1);
}
#endif