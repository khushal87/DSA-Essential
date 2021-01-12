#include <bits/stdc++.h>
using namespace std;

void sortKSorted(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    for (auto j : ans)
    {
        cout << j << " ";
    }
}