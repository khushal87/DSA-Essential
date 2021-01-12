#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[1001];

int main()
{
    int n, m, a, b, w;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, INT_MAX);
    pq.push({0, 1});
    dis[1] = 0;
    while (!pq.empty())
    {
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();

        for (pair<int, int> edge : adj[curr])
        {
            if (curr_d + edge.second < dis[edge.first])
            {
                dis[edge.first] = curr_d + edge.second;
                pq.push({dis[edge.first], edge.first});
            }
        }
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
}