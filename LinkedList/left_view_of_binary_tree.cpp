#include <bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *left, *right;
};

void leftViewUtil(Node *root, int level, int &max_level)
{
    if (root != NULL)
    {
        return;
    }
    if (max_level < level)
    {
        cout << root->data << " ";
        max_level = level;
    }
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}

void leftView(Node *node)
{
    int max_level = 0;
    leftViewUtil(node, 1, max_level);
}