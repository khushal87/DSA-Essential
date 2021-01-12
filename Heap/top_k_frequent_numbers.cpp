#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;

void topKFrequent(int arr[], int n, int k)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    for (auto j : mp)
    {
        pq.push({j.second, j.first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    while (pq.size() != 0)
    {
        cout << pq.top().second << " ";
        pq.pop();
    }
}