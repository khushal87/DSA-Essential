#include <iostream>
using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
};

int getCount(ListNode *root)
{
    ListNode *curr = root;
    int ctr = 0;
    while (curr != nullptr)
    {
        ctr++;
        curr = curr->next;
    }
    return ctr;
}

ListNode *_getIntersectionNode(int d, ListNode *list1, ListNode *list2)
{
    ListNode *curr1 = list1;
    ListNode *curr2 = list2;
    for (int i = 0; i < d; i++)
    {
        if (curr1 == NULL)
        {
            return nullptr;
        }
        curr1 = curr1->next;
    }
    while (curr1 != nullptr && curr2 != nullptr)
    {
        if (curr1 == curr2)
            return curr1;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return nullptr;
}

ListNode *getIntersectionNode(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr)
        return nullptr;
    if (list2 == nullptr)
        return nullptr;
    int ctr1 = getCount(list1);
    int ctr2 = getCount(list2);
    int d;
    if (ctr1 > ctr2)
    {
        d = ctr1 - ctr2;
        return _getIntersectionNode(d, list1, list2);
    }
    else
    {
        d = ctr2 - ctr1;
        return _getIntersectionNode(d, list2, list1);
    }
}