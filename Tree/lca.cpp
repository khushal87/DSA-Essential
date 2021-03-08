#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *lca(Node *root, int n1, int n2)
{
    //Your code here
    if (root == nullptr)
        return nullptr;
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);
    if (left != nullptr && right != nullptr)
        return root;
    else
        return left ? left : right;
}