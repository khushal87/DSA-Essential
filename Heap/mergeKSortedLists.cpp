#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

struct Node
{
    ListNode *curr;
    int idx;
    Node(ListNode *c, int data)
    {
        curr = c;
        idx = data;
    }
};

struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->curr->data > b->curr->data;
    }
};

ListNode *mergeKSortedList(vector<vector<ListNode *>> &lists)
{
    int k = lists.size();
    if (k == 0)
        return nullptr;
    else
    {
        ListNode *head, *tail;
        head = tail = NULL;
        priority_queue<Node, vector<Node>, compare> pq;
        vector<ListNode *> ptr(k);
        for (int i = 0; i < k; i++)
        {
            ptr[i] = lists[i][0];
            if (ptr[i] != nullptr)
            {
                pq.push(Node(ptr[i], i));
            }
        }
        if (pq.empty())
            return nullptr;
        head = tail = pq.top().curr;
        int idx = pq.top().idx;
        pq.pop();
        ptr[idx] = ptr[idx]->next;
        if (ptr[idx] != nullptr)
        {
            pq.push(Node(ptr[idx], idx));
        }
        while (!pq.empty())
        {
            ListNode *temp = pq.top().curr;
            idx = pq.top().idx;
            pq.pop();
            tail->next = temp;
            tail = tail->next;
            ptr[idx] = ptr[idx]->next;
            if (ptr[idx] != nullptr)
            {
                pq.push(Node(ptr[idx], idx));
            }
        }
    }
}