#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int val;
    Tree *left;
    Tree *right;
};

bool isIdentical(Tree *root1, Tree *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    return root1->val == root2->val && isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

bool solve(Tree *root, Tree *target)
{
    if (target == nullptr)
        return true;
    if (root == nullptr)
        return false;
    if (isIdentical(root, target))
        return true;
    return solve(root->left, target) || solve(root->right, target);
}