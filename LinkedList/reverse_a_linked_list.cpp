#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
};

Node *reverse(Node *root)
{
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = root;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    root = prev;
    return root;
}