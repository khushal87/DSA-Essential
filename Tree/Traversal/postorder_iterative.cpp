#include <bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *left, *right;
};

void preOrder(Node *root)
{
    stack<Node *> st;
    stack<int> out;
    st.push(root);
    while (!st.empty())
    {
        Node *top = st.top();
        st.pop();
        out.push(top->data);
        if (root->left != nullptr)
            st.push(root->left);
        if (root->right != nullptr)
            st.push(root->right);
    }
    while (!out.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}