#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int data;
    Tree *left;
    Tree *right;
};

int height(Tree *root)
{
    if (root == nullptr)
        return 0;
    else
    {
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
    }
}

int diameter(Tree *root)
{
    if (root == nullptr)
        return 0;
    else
    {
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        int lDia = diameter(root->left);
        int rDia = diameter(root->right);
        return max(1 + lHeight + rHeight, max(lDia, rDia));
    }
}