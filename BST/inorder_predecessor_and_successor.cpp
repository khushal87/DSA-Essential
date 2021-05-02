#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

pair<Node *, Node *> preSuc(Node *root, int data)
{
    if (root == nullptr)
        return {};
    else
    {
        pair<Node *, Node *> p;
        if (root->data == data)
        {
            if (root->left)
            {
                Node *temp = root->left;
                while (temp->right)
                {
                    temp = temp->right;
                }
                p.first = temp;
            }
            if (root->right)
            {
                Node *temp = root->right;
                while (temp->left)
                {
                    temp = temp->left;
                }
                p.second = temp;
            }
        }
        else if (root->data > data)
        {
            p.second = root;
            preSuc(root->left, data);
        }
        else
        {
            p.first = root;
            preSuc(root->right, data);
        }
        return p;
    }
}