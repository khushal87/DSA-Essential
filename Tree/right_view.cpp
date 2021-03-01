#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<int> rightSideView(TreeNode *root)
{
    if (root == nullptr)
        return {};
    queue<TreeNode *> qu;
    qu.push(root);
    vector<int> ans;
    while (!qu.empty())
    {
        int n = qu.size();
        for (int i = 1; i <= n; i++)
        {
            TreeNode *temp = qu.front();
            qu.pop();
            if (i == n)
            {
                ans.push_back(temp->val);
            }
            if (temp->left != nullptr)
            {
                qu.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                qu.push(temp->right);
            }
        }
    }
    return ans;
}