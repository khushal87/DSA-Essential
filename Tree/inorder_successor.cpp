#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *searchData(Node *root, int data)
{
    if (root == nullptr)
        return nullptr;
    else
    {
        if (root->data == data)
            return root;
        else if (root->data > data)
        {
            return searchData(root->left, data);
        }
        else
        {
            return searchData(root->right, data);
        }
    }
}

int inorderPredecessor(Node *root, int data)
{
    if (root == nullptr)
    {
        return -1;
    }
    else
    {
        Node *p = searchData(root, data);
        if (p->right != nullptr)
        {
            Node *temp = p->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }
            return temp->data;
        }
        else
        {
            Node *s = root;
            Node *ans = NULL;
            while (p->data != s->data)
            {
                if (p->data < s->data)
                {
                    ans = s;
                    s = s->left;
                }
                else
                {
                    s = s->right;
                }
            }
            return ans ? ans->data : 0;
        }
    }
}