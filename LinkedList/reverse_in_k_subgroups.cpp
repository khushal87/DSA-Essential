#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
};

Node *reverse(Node *root, int k)
{
    if (!root)
        return;
    int cnt = 0;
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = root;
    while (curr != nullptr && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    if (next != nullptr)
    {
        root->next = reverse(next, k);
    }
    return prev;
}