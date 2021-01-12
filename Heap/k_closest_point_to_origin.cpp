#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> pppi;

void kClosestPoints(vector<pair<int, int>> points, int n)
{
    priority_queue<pppi> pq;
    for (auto j : points)
    {
        int dis = ((j.second * j.second)) + ((j.first * j.first));
        pq.push({dis, j});
        if (pq.size() > 0)
        {
            pq.pop();
        }
    }
    while (pq.size() > 0)
    {
        cout << pq.top().second.first << " " << pq.top().second.second << endl;
        pq.pop();
    }
}