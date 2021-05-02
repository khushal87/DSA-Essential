#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool findPairUtil(Node *root, int target, set<int> &st)
{
    if (root == nullptr)
        return false;
    if (findPairUtil(root->left, target, st))
    {
        return true;
    }
    if (st.find(target - root->data) != st.end())
    {
        cout << root->data << " " << target - root->data << endl;
        return true;
    }
    else
    {
        st.insert(root->data);
    }
    if (findPairUtil(root->right, target, st))
    {
        return true;
    }
}