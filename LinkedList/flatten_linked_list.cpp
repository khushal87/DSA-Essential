#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *bottom;
};

Node *mergeTwoLinkedList(Node *a, Node *b)
{
    Node *temp = new Node;
    temp->data = 0;
    temp->next = nullptr;
    Node *res = temp;
    while (a != nullptr && b != nullptr)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;
    return res->bottom;
}

Node *flatten(Node *root)
{
    if (root == nullptr || root->next == nullptr)
    {
        return root;
    }
    root->next = flatten(root->next);
    root = mergeTwoLinkedList(root, root->next);
    return root;
}