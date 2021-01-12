#include <bits/stdc++.h>
using namespace std;

stack<int> st, ss;

void push(int a)
{
    st.push(a);
    if (ss.size() == 0 || ss.top() >= a)
    {
        ss.push(a);
    }
}

int pop()
{
    int min = ss.top();
    if (st.size() == 0)
        return -1;
    int ans = st.top();
    st.pop();
    if (min == ans)
    {
        ss.pop();
    }
}

int getMin()
{
    if (ss.size() == 0)
    {
        return -1;
    }
    else
    {
        return ss.top();
    }
}