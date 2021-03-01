#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void getVerticalOrder(Node *root, int hd, map<int, vector<int>> &mp)
{
    if (root == nullptr)
        return;
    mp[hd].push_back(root->data);
    getVerticalOrder(root->left, hd - 1, mp);
    getVerticalOrder(root->right, hd + 1, mp);
}

void printVerticalOrder(Node *root)
{
    map<int, vector<int>> mp;
    int hd = 0;
    getVerticalOrder(root, hd, mp);
    for (auto j : mp)
    {
        for (auto k : j.second)
        {
            cout << k << " ";
        }
    }
}