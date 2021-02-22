#include <bits/stdc++.h>
using namespace std;

stack<int> s1, s2;

void push(int x)
{
    s1.push(x);
}

int pop()
{
    if (s1.empty() && s2.empty())
    {
        cout << "Queue is empty" << endl;
        exit(0);
    }
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int x = s2.top();
    s2.pop();
    return x;
}