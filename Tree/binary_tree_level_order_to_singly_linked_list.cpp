#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
};

class LLNode
{
public:
    int val;
    LLNode *next;
};

LLNode *newNode(int data)
{
    LLNode *temp = new LLNode();
    temp->val = data;
    temp->next = NULL;
    return temp;
}

LLNode *solve(Tree *root)
{
    if (root == nullptr)
        return nullptr;
    else
    {
        queue<Tree *> qu;
        qu.push(root);
        LLNode *prev = new LLNode;
        LLNode *ll = new LLNode;
        prev = ll;
        while (!qu.empty())
        {
            int n = qu.size();
            for (int i = 1; i <= n; i++)
            {
                Tree *temp = qu.front();
                LLNode *newN = newNode(temp->val);
                if (ll == nullptr)
                    ll = newN;
                else
                    ll->next = newN;
                ll = newN;
                qu.pop();
                if (temp->left)
                {
                    qu.push(temp->left);
                }
                if (temp->right)
                {
                    qu.push(temp->right);
                }
            }
        }
        prev = prev->next;
        return prev;
    }
}