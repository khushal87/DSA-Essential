#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void getDiagonalOrder(Node *root, int hd, map<int, vector<int>> &mp)
{
    if (root == nullptr)
        return;
    mp[hd].push_back(root->data);

    //for left decrease by 1
    getDiagonalOrder(root->left, hd - 1, mp);

    //for right remains same
    getDiagonalOrder(root->right, hd, mp);
}

void printDiagonalOrder(Node *root)
{
    map<int, vector<int>> mp;
    int hd = 0;
    getDiagonalOrder(root, hd, mp);
    for (auto j : mp)
    {
        for (auto k : j.second)
        {
            cout << k << " ";
        }
    }
}