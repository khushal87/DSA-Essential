#include <bits/stdc++.h>
using namespace std;

void nextSmallestElement(int arr[], int n)
{
    vector<int> v;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            v.push_back(-1);
        }
        else if (st.size() > 0 && st.top() < arr[i])
        {
            v.push_back(st.top());
        }
        else if (st.size() > 0 && st.top() >= arr[i])
        {
            while (st.size() > 0 && st.top() >= arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    for (auto j : v)
    {
        cout << j << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    nextSmallestElement(arr, n);
    return 0;
}