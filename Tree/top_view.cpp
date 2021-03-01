#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> topView(Node *root)
{
    vector<int> ans;
    map<Node *, int> hdTrace;
    queue<Node *> qu;
    hdTrace[root] = 0;
    map<int, int> mp;
    qu.push(root);
    while (!qu.empty())
    {
        Node *temp = qu.front();
        qu.pop();
        int hd = hdTrace[temp];
        if (mp.count(hd) == 0)
        {
            mp[hd] = temp->data;
        }
        if (temp->left != nullptr)
        {
            hdTrace[temp->left] = hd - 1;
            qu.push(temp->left);
        }
        if (temp->right != nullptr)
        {
            hdTrace[temp->right] = hd + 1;
            qu.push(temp->right);
        }
    }
    for (auto j : mp)
    {
        ans.push_back(j.second);
    }
    return ans;
}