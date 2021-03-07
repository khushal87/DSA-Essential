#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

//using bfs
int minDepth(Node *node)
{
    // Your code here
    if (node == nullptr)
        return 0;
    queue<Node *> qu;
    qu.push(node);
    int ctr = 1;
    while (!qu.empty())
    {
        int n = qu.size();
        for (int i = 1; i <= n; i++)
        {
            Node *temp = qu.front();
            qu.pop();
            if (temp->left == nullptr && temp->right == nullptr)
            {
                return ctr;
            }
            if (temp->left)
            {
                qu.push(temp->left);
            }
            if (temp->right)
            {
                qu.push(temp->right);
            }
        }
        ctr++;
    }
    return ctr;
}