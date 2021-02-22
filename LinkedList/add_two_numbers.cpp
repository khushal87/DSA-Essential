#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *newnode = new Node;
    newnode->data = data;
    newnode->next = nullptr;
    return newnode;
}

Node *addTwoList(Node *head1, Node *head2)
{
    Node *res = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;
    while (head1 != NULL || head2 != NULL)
    {
        sum = carry + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum %= 10;
        temp = newNode(sum);
        if (res == nullptr)
        {
            res = temp;
        }
        else
        {
            prev->next = temp;
        }
        prev = temp;
        if (head1)
            head1 = head1->next;
        if (head2)
            head2 = head2->next;
    }
    if (carry > 0)
    {
        temp->next = newNode(carry);
    }
    return res;
}