#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue<Node *> qu;
    stack<Node *> st;
    vector<int> ans;
    qu.push(root);
    while (!qu.empty())
    {
        int n = qu.size();
        for (int i = 1; i <= n; i++)
        {
            Node *top = qu.front();
            qu.pop();
            st.push(top);

            if (top->right)
                qu.push(top->right);

            if (top->left)
                qu.push(top->left);
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top()->data);
        st.pop();
    }
    return ans;
}