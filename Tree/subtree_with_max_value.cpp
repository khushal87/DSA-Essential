#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
};

int findLargest(Tree *root, int &ans)
{
    if (root == nullptr)
        return 0;
    else
    {
        int sum = root->val + findLargest(root->left, ans) + findLargest(root->right, ans);
        ans = max(ans, sum);
        return sum;
    }
}

int solve(Tree *root)
{
    if (root == nullptr)
        return 0;
    int ans = 0;
    findLargest(root, ans);
    return ans;
}