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

Node *removeDuplicates(Node *head)
{
    // your code goes here
    unordered_set<int> st;
    Node *curr = head;
    Node *prev = nullptr;
    while (curr != nullptr)
    {
        if (st.find(curr->data) != st.end())
        {
            prev->next = curr->next;
            delete curr;
        }
        else
        {
            st.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}