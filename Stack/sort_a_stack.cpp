#include <bits/stdc++.h>
using namespace std;

void insertBottom(stack<int> &st, int x)
{
    if (st.size() == 0 || x > st.top())
        st.push(x);
    else
    {
        int temp = st.top();
        st.pop();
        insertBottom(st, x);
        st.push(temp);
    }
}

void reverse(stack<int> &st)
{
    if (st.size() > 0)
    {
        int x = st.top();
        st.pop();
        reverse(st);
        insertBottom(st, x);
    }
}