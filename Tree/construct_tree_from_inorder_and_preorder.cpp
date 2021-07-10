#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int search(vector<int> in, int start, int end, int x)
{
    int idx = 0;
    for (int i = start; i <= end; i++)
    {
        if (in[i] == x)
        {
            idx = i;
        }
    }
    return idx;
}

int preIdx = 0;
Node *solve(vector<int> &pre, vector<int> &in, int start, int end)
{

    if (start > end)
    {
        return nullptr;
    }
    Node *tNode = new Node(pre[preIdx++]);
    if (start == end)
    {
        return tNode;
    }
    int idx = search(in, start, end, tNode->data);
    tNode->left = solve(pre, in, start, idx - 1);
    tNode->right = solve(pre, in, idx + 1, end);
    return tNode;
}

Node *buildTree(vector<int> &pre, vector<int> &in)
{
    int start = 0;
    int end = in.size() - 1;
    return solve(pre, in, start, end);
}