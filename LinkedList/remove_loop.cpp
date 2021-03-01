#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
};

void removeLoop(Node *loop_node, Node *head)
{
    Node *ptr1, *ptr2;
    ptr1 = head;
    while (1)
    {
        ptr2 = loop_node;
        while (ptr2->next != loop_node && ptr2->next != ptr1)
        {
            if (ptr2->next == ptr1)
            {
                break;
            }
            ptr1 = ptr1->next;
        }
    }
    ptr2->next = nullptr;
}

//fastest approach
bool detectLoop1(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && slow && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            removeLoop(slow, head);
        }
    }
    return false;
}
