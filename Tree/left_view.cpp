#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void leftView(Node *root)
{
    if (!root)
        return;
    else
    {
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
                    cout << temp->data << " ";
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
    }
}