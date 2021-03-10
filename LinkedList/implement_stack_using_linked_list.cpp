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

Node *top = NULL;

void push(int data)
{
    Node *temp = new Node(data);
    if (!temp)
    {
        cout << "\nHeap Overflow" << endl;
        return;
    }
    temp->next = top;
    top = temp;
}

bool isEmpty()
{
    return top == nullptr;
}

int peek()
{
    if (!isEmpty())
    {
        return top->data;
    }
    else
    {
        return -1;
    }
}

void pop()
{
    Node *temp;
    if (top == nullptr)
    {
        cout << "\nStack Underflow" << endl;
        return;
    }
    else
    {
        temp = top;
        top = top->next;
        delete temp;
    }
}
