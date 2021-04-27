#include <bits/stdc++.h>
using namespace std;

class LLNode
{
public:
    int val;
    LLNode *next;
};

LLNode *solve(LLNode *node)
{
    if (!node)
        return nullptr;
    LLNode *res = new LLNode();
    res = node;
    int jum = node->val;
    for (int i = 0; i < jum && (node); i++)
    {
        node = node->next;
    }
    res->next = solve(node);
    return res;
}