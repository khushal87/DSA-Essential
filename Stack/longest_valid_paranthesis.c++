#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestValidParanthesis(string s)
{
    int n = s.length();
    stack<int> st;
    st.push(-1);

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
            if (!st.empty())
            {
                result = max(result, i - st.top());
            }
            else
            {
                st.push(i);
            }
        }
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    int ans = lengthOfLongestValidParanthesis(s);
    cout << "Length = " << ans << endl;
}