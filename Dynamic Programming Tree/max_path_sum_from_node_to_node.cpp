#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

int solve(Node *root, int &res)
{
    if (root == nullptr)
        return 0;
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    int temp = max(max(l, r) + root->data, root->data);
    int ans = max(temp, root->data + l + r);
    res = max(ans, temp);
    return temp;
}

int main()
{
    int res = INT_MIN;
    Node *root;
    solve(root, res);
    cout << res << endl;
}