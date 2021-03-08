#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *temp = NULL;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int search(vector<int> in, int start, int end, int x)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == x)
        {
            return i;
        }
    }
}

Node *buildTree(vector<int> in, vector<int> pre, int start, int end)
{
    static int preIdx = 0;
    if (start > end)
    {
        return nullptr;
    }
    Node *tNode = newNode(pre[preIdx++]);
    if (start == end)
    {
        return tNode;
    }
    int idx = search(in, start, end, tNode->data);
    tNode->left = buildTree(in, pre, start, preIdx - 1);
    tNode->right = buildTree(in, pre, preIdx + 1, end);
    return tNode;
}