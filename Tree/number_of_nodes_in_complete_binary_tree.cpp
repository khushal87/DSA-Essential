#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

int getHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    else
    {
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        return 1 + max(lh, rh);
    }
}

int countNodes(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    else
    {
        int cntLeft = getHeight(root->left);
        int cntRight = getHeight(root->right);
        if (cntLeft == cntRight)
        {
            return pow(2, cntLeft) + countNodes(root->right);
        }
        else
        {
            return pow(2, cntRight) + countNodes(root->left);
        }
    }
}