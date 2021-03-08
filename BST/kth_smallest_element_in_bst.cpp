#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int solve(Node *root, int &k)
{
    if (root == nullptr)
        return 0;
    else
    {
        int left = solve(root->left, k);
        if (left)
            return left;
        k -= 1;
        if (k == 0)
        {
            return root->data;
        }
        int right = solve(root->right, k);
        return right;
    }
}