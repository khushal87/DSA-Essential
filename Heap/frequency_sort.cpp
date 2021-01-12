#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;

void topKFrequent(int arr[], int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    priority_queue<ppi> pq;
    for (auto j : mp)
    {
        pq.push({j.second, j.first});
    }
    while (pq.size() != 0)
    {
        for (int i = 1; i <= pq.top().first; i++)
            cout << pq.top().second << " ";
        pq.pop();
    }
}