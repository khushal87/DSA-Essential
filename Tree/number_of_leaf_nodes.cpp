#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int countLeaves(Node *root)
{
    // Your code here
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    else
    {
        return countLeaves(root->left) +
               countLeaves(root->right);
    }
}