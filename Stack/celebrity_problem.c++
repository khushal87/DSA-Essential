#include <bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>> &mat, int a, int b)
{
    return mat[a][b];
}

int findCeleb(vector<vector<int>> &mat, int n)
{
    stack<int> st;
    int c;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    int a = st.top();
    st.pop();
    int b = st.top();
    st.pop();
    while (st.size() > 1)
    {
        if (knows(mat, a, b))
        {
            a = st.top();
            st.pop();
        }
        else
        {
            b = st.top();
            st.pop();
        }
    }
    if (st.empty())
        return -1;
    c = st.top();
    st.pop();
    if (knows(mat, c, a))
        c = a;
    if (knows(mat, c, b))
        c = b;
    for (int i = 0; i < n; i++)
    {
        if ((i != c) && (knows(mat, c, i) || !knows(mat, i, c)))
        {
            return -1;
        }
    }
    return c;
}