#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmallestElement(vector<int> arr, int n)
{
    vector<int> left;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            left.push_back(-1);
        }
        else if (st.size() > 0 && st.top().first < arr[i])
        {
            left.push_back(st.top().second);
        }
        else if (st.size() > 0 && st.top().first >= arr[i])
        {
            while (st.size() > 0 && st.top().first >= arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                left.push_back(-1);
            }
            else
            {
                left.push_back(st.top().second);
            }
        }
        st.push({arr[i], i});
    }
    return left;
}

vector<int> nextSmallestElement(vector<int> arr, int n)
{
    vector<int> right;
    stack<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            right.push_back(n);
        }
        else if (st.size() > 0 && st.top().first < arr[i])
        {
            right.push_back(st.top().second);
        }
        else if (st.size() > 0 && st.top().first >= arr[i])
        {
            while (st.size() > 0 && st.top().first >= arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                right.push_back(n);
            }
            else
            {
                right.push_back(st.top().second);
            }
        }
        st.push({arr[i], i});
    }
    reverse(right.begin(), right.end());
    return right;
}

int maxAreaOfHistogram(vector<int> arr, int n)
{
    vector<int> left = previousSmallestElement(arr, n);
    vector<int> right = nextSmallestElement(arr, n);
    vector<int> width;
    for (int i = 0; i < left.size(); i++)
    {
        width[i] = right[i] - left[i] - 1;
    }
    vector<int> area;
    for (int i = 0; i < n; i++)
    {
        area[i] = width[i] * arr[i];
    }
    return *max_element(area.begin(), area.end());
}

int maxAreaRectangle(vector<vector<int>> arr, int n, int m)
{
    vector<int> v;
    for (int j = 0; j < m; j++)
        v.push_back(arr[0][j]);
    int mah = maxAreaOfHistogram(v, v.size());
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                v[j] = 0;
            }
            else
            {
                v[j] = v[j] + arr[i][j];
            }
        }
        mah = max(mah, maxAreaOfHistogram(v, v.size()));
    }
    return mah;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n);
    int x;
    for (int i = 0; i < n; i++)
    {
        vector<int> sub;
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            sub.push_back(x);
        }
        arr.push_back(sub);
    }
    maxAreaRectangle(arr, n, m);
    return 0;
}