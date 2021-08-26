#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool areIdentical(TreeNode *root, TreeNode *subRoot)
{
    if (root == nullptr && subRoot == nullptr)
        return true;
    if (root == nullptr || subRoot == nullptr)
        return false;
    if (root->val == subRoot->val && areIdentical(root->left, subRoot->left) && areIdentical(root->right, subRoot->right))
    {
        return true;
    }
    return false;
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (root == nullptr)
        return false;
    if (subRoot == nullptr)
        return true;
    if (areIdentical(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}