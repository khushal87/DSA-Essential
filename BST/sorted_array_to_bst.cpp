#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int data;
    Tree *left;
    Tree *right;
};

Tree *newNode(int data)
{
    Tree *temp;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Tree *sortedArrayToBST(vector<int> arr, int start, int end)
{
    if (start > end)
        return nullptr;
    else
    {
        int mid = start + (end - start) / 2;
        Tree *root = newNode(arr[mid]);
        root->left = sortedArrayToBST(arr, start, mid - 1);
        root->right = sortedArrayToBST(arr, mid + 1, end);
        return root;
    }
}