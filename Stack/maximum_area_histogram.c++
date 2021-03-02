#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmallestElement(int arr[], int n)
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

vector<int> nextSmallestElement(int arr[], int n)
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

int maxAreaOfHistogram(int arr[], int n)
{
    vector<int> left = previousSmallestElement(arr, n);
    vector<int> right = nextSmallestElement(arr, n);
    vector<int> width;
    for (int i = 0; i < left.size(); i++)
    {
        width[i] = right[i] - left[i] - 1;
        cout << width[i] << " ";
    }
    cout << endl;
    vector<int> area;
    for (int i = 0; i < n; i++)
    {
        area[i] = width[i] * arr[i];
    }
    return *max_element(area.begin(), area.end());
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
    cout << maxAreaOfHistogram(arr, n);
    return 0;
}