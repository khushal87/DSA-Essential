#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool isIsomorphic(Node *tree1, Node *tree2)
{
    if (tree1 == nullptr && tree2 == nullptr)
    {
        return true;
    }
    if (tree1 == nullptr || tree2 == nullptr)
        return false;
    if (tree1->data != tree2->data)
        return false;
    if ((isIsomorphic(tree1->left, tree2->left) &&
         isIsomorphic(tree1->right, tree2->right)) ||
        (isIsomorphic(tree1->left, tree2->right) &&
         isIsomorphic(tree1->right, tree2->left)))
        return true;
}