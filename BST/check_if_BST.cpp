#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool isBSTUtil(Node *root, int min, int max)
{
    if (root == nullptr)
        return true;
    if (root->data > min && root->data < max)
    {
        return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
    }
    return false;
}

bool isBST(Node *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}