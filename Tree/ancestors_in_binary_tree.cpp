#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

bool pri(Node *root, int target, vector<int> &ans)
{
    if (root == nullptr)
        return false;
    if (root->data == target)
        return true;
    if (pri(root->left, target, ans) || pri(root->right, target, ans))
    {
        ans.push_back(root->data);
        return true;
    }
    return false;
}

vector<int> Ancestors(struct Node *root, int target)
{
    // Code here
    vector<int> ans;
    bool pi = pri(root, target, ans);
    return ans;
}