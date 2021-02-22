#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
};

Node *mergeLinkedList(Node *first, Node *second)
{
    Node *result = nullptr;
    if (first == nullptr)
    {
        return second;
    }
    if (second == nullptr)
    {
        return first;
    }
    if (first->data <= second->data)
    {
        result = first;
        result->next = mergeLinkedList(first->next, second);
    }
    else
    {
        result = second;
        result->next = mergeLinkedList(first, second->next);
    }
    return result;
}