#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    // your code goes here
    if (head == nullptr)
        return nullptr;
    Node *curr = head;
    Node *next;
    while (curr->next != nullptr)
    {
        if (curr->data == curr->next->data)
        {
            next = curr->next->next;
            free(curr->next);
            curr->next = next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}