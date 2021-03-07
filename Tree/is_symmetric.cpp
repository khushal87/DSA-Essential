#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

//utitlity to check if two tree are mirror of each other
bool isMirror(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 && root2)
    {
        return root1->data == root2->data && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
    return false;
}

bool isSymmetric(struct Node *root)
{
    return isMirror(root, root);
}