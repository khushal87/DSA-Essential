#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int height(Node *root)
{
    if (root == nullptr)
        return 0;
    else
    {
        return 1 + max(height(root->left), height(root->right));
    }
}

bool heightBalancedOrNot(Node *root)
{
    if (root == nullptr)
        return true;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    if (abs(lHeight - rHeight) <= 1 && heightBalancedOrNot(root->left) && heightBalancedOrNot(root->right))
        return true;
    else
        return false;
}