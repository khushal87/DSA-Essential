#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// method 1
int countNodes(Node *root)
{
    if (root == nullptr)
        return 0;
    else
        1 + countNodes(root->left) + countNodes(root->right);
}

bool isComplete(Node *root, int idx, int numNodes)
{
    if (root == nullptr)
        return true;
    if (idx >= numNodes)
    {
        return false;
    }
    return isComplete(root->left, 2 * idx + 1, numNodes) && isComplete(root->right, 2 * idx + 2, numNodes);
}

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