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
        inorder(root->left, k, c, ans);
        c++;
        if (c == k)
        {
            ans = root->data;
            return;
        }
        inorder(root->right, k, c, ans);
    }
}

int solve(Node *root, int k)
{
    if (root == nullptr)
        return 0;
    else
    {
        int ans = 0;
        int n = 0;
        inorder(root, k + 1, n, ans);
        return ans;
    }
}