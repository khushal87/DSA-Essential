#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void inorder(Node *root, int k, int &c, int &ans)
{
    if (root == nullptr)
        return;
    else
    {
        inorder(root->right, k, c, ans);
        c++;
        if (c == k)
        {
            ans = root->data;
            return;
        }
        inorder(root->left, k, c, ans);
    }
}

int kthLargest(Node *root, int k)
{
    //Your code here
    if (root == nullptr)
        return 0;
    else
    {
        int ans = 0;
        int n = 0;
        inorder(root, k, n, ans);
        return ans;
    }
}