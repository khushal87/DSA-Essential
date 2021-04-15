#include <bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *left, *right;
};

void inOrder(Node *root)
{
    stack<Node *> st;
    Node *curr = root;
    while (!st.empty() || curr != nullptr)
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}