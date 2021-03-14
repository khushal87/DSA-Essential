#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void reverse(Node *root1, Node *root2, int level)
{
    if (root1 == nullptr || root2 == nullptr)
        return;
    else
    {
        if (level % 2 == 0)
        {
            swap(root1->data, root2->data);
        }
        reverse(root1->left, root2->right, level + 1);
        reverse(root1->right, root2->left, level + 1);
    }
}

void reverseAlternate(Node *root)
{
    //Your code here
    int lev = 0;
    reverse(root->left, root->right, lev);
}