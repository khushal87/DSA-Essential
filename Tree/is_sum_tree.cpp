#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int val;
    Tree *left;
    Tree *right;
};

bool solve(Tree *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return 1;
    else
    {
        int left = 0, right = 0;
        if (root->left)
            left = root->left->val;
        if (root->right)
            right = root->right->val;
        if (((left + right) == root->val) && solve(root->left) && solve(root->right))
            return true;
        else
            return false;
    }
}