#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> leftView(Node *root)
{
    if (!root)
        return {};
    else
    {
        vector<int> ans;
        queue<Node *> qu;
        qu.push(root);
        while (!qu.empty())
        {
            int n = qu.size();
            for (int i = 1; i <= n; i++)
            {
                Node *temp = qu.front();
                qu.pop();
                if (i == 1)
                {
                    ans.push_back(temp->data);
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
}