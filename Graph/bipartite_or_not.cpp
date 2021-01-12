#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &color, int i, int col)
{
    vis[i] = true;
    color[i] = col;
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            if (isBipartite(adj, vis, color, j, col ^ 1) == false)
            {
                return false;
            }
        }
        else
        {
            if (color[i] == color[j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<bool> vis(n + 1, false);
    vector<int> color(n + 1, false);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << isBipartite(adj, vis, color, 1, 1);
}