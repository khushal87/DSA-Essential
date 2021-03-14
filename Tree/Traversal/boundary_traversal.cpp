#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void printLeaves(Node *root)
{
    if (root == nullptr)
        return;
    else
    {
        printLeaves(root->left);
        if (root->left == nullptr && root->right == nullptr)
            cout << root->data << " ";
        printLeaves(root->right);
    }
}

void printLeft(Node *root)
{
    if (root == nullptr)
        return;
    else
    {
        if (root->left)
        {
            cout << root->data << " ";
            printLeft(root->left);
        }
        else if (root->right)
        {
            cout << root->data << " ";
            printLeft(root->right);
        }
    }
}

// ************bottom up printing
void printRight(Node *root)
{
    if (root == nullptr)
        return;
    else
    {
        if (root->right)
        {
            printRight(root->right);
            cout << root->data << " ";
        }
        else if (root->left)
        {
            printRight(root->left);
            cout << root->data << " ";
        }
    }
}

void printBoundary(Node *root)
{
    if (root == nullptr)
        return;
    else
    {
        cout << root->data << " ";
        printLeft(root->left);
        printLeaves(root->left);
        printLeaves(root->right);
        printRight(root->right);
    }
}