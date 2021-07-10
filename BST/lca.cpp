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
    if (root->data > n1 && root->data > n2)
    {
        return lca(root->left, n1, n2);
    }
    else if (root->data < n1 && root->data < n2)
    {
        return lca(root->right, n1, n2);
    }
    return root;
}