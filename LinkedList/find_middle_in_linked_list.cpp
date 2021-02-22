#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
};

//fastest approach
Node *middleElement(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && slow && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
