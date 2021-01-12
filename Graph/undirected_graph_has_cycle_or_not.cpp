#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, vector<bool> &vis, int i, int parent)
{
    vis[i] = true;
    for (auto j : adj[i])
    {
        if (vis[j] == false)
        {
            if (dfs(adj, vis, j, parent) == true)
            {
                return true;
            }
            else
            {
                if (j != parent)
                {
                    return true;
                }
            }
        }
    }
    return false;
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
    dfs(adj, vis, 1, -1);
}