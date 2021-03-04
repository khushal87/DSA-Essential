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
    if (root1->val != root2->val)
        return false;
    bool op1 = isIdentical(root1->left, root2->left) &&
               isIdentical(root1->right, root2->right);
    bool op2 = isIdentical(root1->left, root2->right) &&
               isIdentical(root1->right, root2->left);
    return op1 || op2;
}

bool solve(Tree *source, Tree *target)
{
    if (target == nullptr)
        return false;
    if (source == nullptr)
        return true;
    if (isIdentical(target, source))
        return true;
    return solve(source, target->left) || solve(source, target->right);
}