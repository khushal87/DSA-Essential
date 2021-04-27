#include <bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
};

Node *removeNthFromEnd(Node *head, int n)
{
    Node *start = new Node();
    start->next = head;
    Node *first = start;
    Node *second = start;
    for (int i = 0; i < n; i++)
    {
        second = second->next;
    }
    while (second->next != NULL)
    {
        first = first->next;
        second = second->next;
    }
    first->next = first->next->next;
    return start->next;
}