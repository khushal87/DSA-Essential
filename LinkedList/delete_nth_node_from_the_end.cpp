#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
};

Node *deleteFunction(Node *head, int key)
{
    Node *first = head;
    Node *second = head;
    for (int i = 0; i < key; i++)
    {
        if (second->next == NULL)
        {
            if (i == key - 1)
            {
                head = head->next;
            }
            return head;
        }
        second = second->next;
    }
    while (second->next != NULL)
    {
        first = first->next;
        second = second->next;
    }
    first->next = first->next->next;
    return head;
}