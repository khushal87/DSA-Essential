#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

pair<int, int> floorCeil(Node *root, int key)
{
    if (root == nullptr)
        return {};
    else
    {
        pair<int, int> p;
        if (root->data == key)
        {
            p.first = root->data;
            p.second = root->data;
        }
        else if (root->data < key)
        {
            p.first = root->data;
            root = root->right;
        }
        else
        {
            p.second = root->data;
            root = root->left;
        }
        return p;
    }
}