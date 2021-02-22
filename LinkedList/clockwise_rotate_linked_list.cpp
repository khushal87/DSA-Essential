#include <iostream>
using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
};

int getCount(ListNode *head)
{
    int ctr = 0;
    ListNode *curr = head;
    while (curr != NULL)
    {
        ctr++;
        curr = curr->next;
    }
    return ctr;
}

ListNode *rotateRight(ListNode *head, int k)
{
    if (k == 0 || head == nullptr)
    {
        return head;
    }
    else
    {
        int n = getCount(head);
        cout << n;
        if (k > n)
        {
            k %= n;
        }
        k = n - k;
        if (k == 0)
        {
            return head;
        }
        ListNode *curr = head;
        while (curr->next != nullptr)
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
        return head;
    }
}