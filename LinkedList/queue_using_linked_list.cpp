#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node *front = nullptr;
Node *rear = nullptr;

void enQueue(int data)
{
    Node *temp = new Node(data);
    if (rear == nullptr)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void deQueue()
{
    if (front == nullptr)
        return;
    Node *temp = front;
    front = front->next;
    if (front == nullptr)
        rear = nullptr;
    delete temp;
}