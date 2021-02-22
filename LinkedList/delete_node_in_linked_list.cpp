#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
};

void deleteNode(Node *node)
{
    Node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete temp;
}