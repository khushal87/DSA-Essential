#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

//Concept is based on full node. A node is ‘Full Node’ if both left and right children are not empty
bool checkComplete(Node *root)
{
    if (root == nullptr)
        return true;
    queue<Node *> que;
    que.push(root);
    bool flag = false;
    while (!que.empty())
    {
        Node *temp = que.front();
        que.pop();
        if (temp->left)
        {
            if (flag == true)
                return false;
            que.push(temp->left);
        }
        else
        {
            flag = true;
        }
        if (temp->right)
        {
            if (flag == true)
                return false;
            que.push(temp->right);
        }
        else
        {
            flag = true;
        }
    }
    return true;
}