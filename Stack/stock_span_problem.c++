#include <bits/stdc++.h>
using namespace std;

//is a variation of nearest greater element to left(previous greater element)
void stockSpanProblem(int arr[], int n)
{
    vector<int> v;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            v.push_back(-1);
        }
        else if (st.size() > 0 && st.top().first > arr[i])
        {
            v.push_back(st.top().second);
        }
        else if (st.size() > 0 && st.top().first <= arr[i])
        {
            while (st.size() > 0 && st.top().first <= arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(st.top().second);
            }
        }
        st.push({arr[i], i});
    }
    for (int i = 0; i < n; i++)
    {
        cout << i - v[i] << " ";
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
    stockSpanProblem(arr, n);
    return 0;
}