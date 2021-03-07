#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int data;
    Tree *left;
    Tree *right;
};

int height(Tree *node)
{
    if (node == nullptr)
        return 0;
    else
    {
        int lh = height(node->left);
        int rh = height(node->right);
        return 1 + max(lh, rh);
    }
}

void leftToRight(Tree *root, int level)
{
    if (root == nullptr)
        return;
    if (level == 1)
    {
        cout << root->data << " ";
    }
    else if (level > 1)
    {
        leftToRight(root->left, level - 1);
        leftToRight(root->right, level - 1);
    }
}

void rightToLeft(Tree *root, int level)
{
    if (root == nullptr)
        return;
    if (level == 1)
    {
        cout << root->data << " ";
    }
    else if (level > 1)
    {
        rightToLeft(root->right, level - 1);
        rightToLeft(root->left, level - 1);
    }
}

void traversal(Tree *root)
{
    int i = 1;
    int j = height(root);
    bool flag = false;
    while (i <= j)
    {
        if (flag == 0)
        {
            rightToLeft(root, i);
            flag = 1;
            i++;
        }
        else
        {
            leftToRight(root, j);
            flag = 0;
            j--;
        }
    }
}
