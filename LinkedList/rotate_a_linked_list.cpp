#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int val;
    Node *next;
};

void rotate(Node *head, int k)
{
    if (k == 0 || head == nullptr)
    {
        return;
    }
    else
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            curr = curr->next;
        }
        curr->next = head;
        curr = head;
        for (int i = 0; i < k - 1; i++)
        {
            curr = curr->next;
        }
        head = curr->next;
        curr->next = nullptr;
    }
}