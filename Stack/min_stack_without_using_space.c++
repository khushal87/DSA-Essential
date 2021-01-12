#include <bits/stdc++.h>
using namespace std;

stack<int> st;
int minel;

void push(int a)
{
    if (st.empty())
    {
        st.push(a);
        minel = a;
    }
    else
    {
        if (a >= minel)
        {
            st.push(a);
        }
        else
        {
            st.push(2 * a - minel);
            minel = a;
        }
    }
}

int pop()
{
    if (st.empty())
        return -1;
    else
    {
        if (st.top() >= minel)
        {
            st.pop();
        }
        else
        {
            int top = 2 * minel - st.top();
            st.pop();
            return top;
        }
    }
}

int getMin()
{
    return st.size() == 0 ? -1 : minel;
}

int top()
{
    return st.empty() ? -1 : st.top() < minel ? minel : st.top();
}