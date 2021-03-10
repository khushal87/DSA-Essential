#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void sortList(Node *root)
{
    vector<int> cnt(3, 0);
    Node *curr = root;
    while (curr != nullptr)
    {
        cnt[curr->data]++;
        curr = curr->next;
    }
    int i = 0;
    curr = root;
    while (curr != nullptr)
    {
        if (cnt[i] == 0)
        {
            i++;
        }
        else
        {
            curr->data = i;
            cnt[i]--;
            curr = curr->next;
        }
    }
}