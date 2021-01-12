#include <bits/stdc++.h>
using namespace std;

void kClosestElements(int arr[], int n, int x, int k)
{
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({abs(x - arr[i]), arr[i]});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        cout << pq.top().second << " ";
        pq.pop();
    }
}