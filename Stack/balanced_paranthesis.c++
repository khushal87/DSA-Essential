#include <bits/stdc++.h>
using namespace std;

bool solve(string s)
{
    stack<char> st;
    for (auto j : s)
    {
        if (j == '(' || j == '[' || j == '{')
        {
            st.push(j);
        }
        else
        {
            if (st.empty())
            {
                st.push(j);
            }
            else
            {
                char x = st.top();
                if ((j == ']' && x == '[') || (j == '}' && x == '{') || (j == ')' && x == '('))
                {
                    st.pop();
                }
                else
                {
                    st.push(j);
                }
            }
        }
    }
    return st.empty();
}