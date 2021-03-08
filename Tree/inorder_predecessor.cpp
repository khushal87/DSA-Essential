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
        if (p->left != nullptr)
        {
            Node *temp = p->left;
            while (temp->right != nullptr)
            {
                temp = temp->right;
            }
            return temp->data;
        }
        else
        {
            Node *s = root;
            Node *ans = NULL;
            while (p->data != s->data)
            {
                if (p->data > s->data)
                {
                    ans = s;
                    s = s->right;
                }
                else
                {
                    s = s->left;
                }
            }
            return ans ? ans->data : 0;
        }
    }
}