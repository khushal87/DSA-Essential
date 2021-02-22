#include <bits/stdc++.h>
using namespace std;

queue<int> q1, q2;
int curr = 0;

void push(int x)
{
    curr++;
    q2.push(x);
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
}

void pop()
{
    if (q1.empty())
        return;
    else
    {
        q1.pop();
        curr--;
    }
}

int top()
{
    if (q1.size() == 0)
        return -1;
    else
        return q1.front();
}

int size()
{
    return curr;
}