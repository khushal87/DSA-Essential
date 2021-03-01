#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int value;
    Tree *left;
    Tree *right;
};

bool hasPathWithGivenSum(Tree *t, int s)
{
    if (t == nullptr)
        return 0 == s;
    else
    {
        int sub = s - t->value;
        bool ans = 0;
        if (sub == 0 && t->left == nullptr && t->right == nullptr)
        {
            return true;
        }
        if (t->left)
        {
            ans = ans || hasPathWithGivenSum(t->left, sub);
        }
        if (t->right)
        {
            ans = ans || hasPathWithGivenSum(t->right, sub);
        }
        return ans;
    }
}