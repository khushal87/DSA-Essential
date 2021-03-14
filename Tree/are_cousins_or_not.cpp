#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int isSibling(Node *root, Node *a, Node *b)
{
    if (root == nullptr)
        return false;
    else
    {
        if ((root->left == a && root->right == b) || (root->right == a && root->left == b))
        {
            return true;
        }
        isSibling(root->left, a, b);
        isSibling(root->right, a, b);
    }
}

int level(Node *root, Node *ptr, int lev)
{
    if (root == nullptr)
        return 0;
    else if (root == ptr)
        return lev;
    int l = level(root->left, ptr, lev + 1);
    if (l != 0)
        return l;
    return level(root->right, ptr, lev + 1);
}

//dfs approach
bool areCousins(Node *root, Node *a, Node *b)
{
    if ((level(root, a, 1) == level(root, b, 1)) && !isSibling(root, a, b))
    {
        return true;
    }
    else
        return false;
}

//bfs approach
bool isCousins(Node *root, int a, int b)
{
    if (root == nullptr)
        return false;
    else
    {
        queue<Node *> qu;
        qu.push(root);

        Node *temp = nullptr;
        while (!qu.empty())
        {
            int cnt = 0;
            int n = qu.size();
            for (int i = 1; i <= n; i++)
            {
                temp = qu.front();
                qu.pop();
                if (temp->left && ((temp->left->data == a) || (temp->left->data == b)))
                {
                    cnt++;
                }
                else if (temp->right && ((temp->right->data == a) || (temp->right->data == b)))
                {
                    cnt++;
                }
                if (temp->left)
                    qu.push(temp->left);
                if (temp->right)
                    qu.push(temp->right);
            }
            if (cnt == 2)
                return true;
        }
        return false;
    }
}