#include <bits/stdc++.h>
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
            return true;
        }
    }
    return false;
}

int main()
{
}