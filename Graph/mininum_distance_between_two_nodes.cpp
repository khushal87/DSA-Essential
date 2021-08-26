#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dis, int i)
{
    queue<int> q;
    q.push(i);
    vis[i] = true;
    dis[i] = 0;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto j : adj[temp])
        {
            if (!vis[j])
            {
                q.push(j);
                dis[j] = (dis[temp] + 1);
                vis[j] = true;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e;
        cin >> n >> e;
        vector<bool> vis(n + 1, false);
        vector<vector<int>> adj(n + 1);
        vector<int> dis(n + 1);
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs(adj, vis, dis, 1);
        cout << dis[n] << endl;
    }
}