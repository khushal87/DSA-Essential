#include <bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *left, *right;
};

vector<int> zigzag(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    stack<Node *> curr, next;
    curr.push(root);
    bool ltr = true;
    while (!curr.empty())
    {
        Node *top = curr.top();
        curr.pop();
        if (top)
        {
            ans.push_back(top->data);
            if (ltr)
            {
                if (top->left)
                {
                    next.push(top->left);
                }
                if (top->right)
                {
                    next.push(top->right);
                }
            }
            else
            {
                if (top->right)
                {
                    next.push(top->right);
                }
                if (top->left)
                {
                    next.push(top->left);
                }
            }
        }
        if (curr.empty())
        {
            ltr = !ltr;
            swap(curr, next);
        }
    }
    return ans;
}
