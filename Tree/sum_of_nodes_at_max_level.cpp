#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int data;
    Tree *left;
    Tree *rigth;
};

int maxLevel = INT_MIN, sum = 0;
void sumOfNodes(Tree *root, int level)
{
    if (root == nullptr)
        return;
    else
    {
        if (level > maxLevel)
        {
            maxLevel = level;
            sum = root->data;
        }
        if (level == maxLevel)
        {
            sum += root->data;
        }
        sumOfNodes(root->left, level + 1);
        sumOfNodes(root->rigth, level + 1);
    }
}