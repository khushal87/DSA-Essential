#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<bool> &vis, int i)
{
    queue<int> q;
    q.push(i);
    vis[i] = true;
    while (!q.empty())
    {
        int temp = q.front();
        cout << temp << " ";
        q.pop();
        for (auto j : adj[temp])
        {
            if (!vis[j])
            {
                q.push(j);
                vis[j] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<bool> vis(n + 1, false);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(adj, vis, 1);
}