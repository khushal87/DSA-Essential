#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
};

bool detectLoop(Node *head)
{
    // your code here
    unordered_set<Node *> st;
    while (head != nullptr)
    {
        if (st.find(head) != st.end())
        {
            return true;
        }
        st.insert(head);
        head = head->next;
    }
    return false;
}

//fastest approach
Node *detectLoop1(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *entry = head;
    while (fast && slow && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            while (slow != entry)
            {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return nullptr;
}
