#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dis, int i, int distance)
{
    vis[i] = true;
    dis[i] = distance;
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            dfs(adj, vis, dis, j, dis[i] + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<bool> vis(n + 1, false);
    vector<int> distance(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //node and distance
    dfs(adj, vis, distance, 0, 1);
    int k;
    cin >> k;
    int ans = -1;
    int min = INT_MAX;
    while (k--)
    {
        int girl;
        cin >> girl;
        if (distance[girl] < min)
        {
            min = distance[girl];
            ans = girl;
        }
        else if (distance[girl] == min && girl < ans)
        {
            ans = girl;
        }
    }
    cout << ans << endl;
}