#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void longestConsecutiveUtil(Node *root, int curr, int expectation, int &ctr)
{
    if (root == nullptr)
        return;
    else
    {
        if (root->data == expectation)
        {
            curr++;
        }
        else
        {
            curr = 1;
        }
        ctr = max(ctr, curr);
        longestConsecutiveUtil(root->left, curr, root->data + 1, ctr);
        longestConsecutiveUtil(root->right, curr, root->data + 1, ctr);
    }
}

int longestConsecutive(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int ctr = 0;
    longestConsecutiveUtil(root, 0, root->data, ctr);
    return ctr;
}