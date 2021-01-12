#include <bits/stdc++.h>
using namespace std;

bool detectCycleUtil(vector<vector<int>> adj, int v, vector<bool> &vis, vector<bool> &recStack)
{
    if (vis[v] == false)
    {
        vis[v] = true;
        recStack[v] = true;
        for (auto it : adj[v])
        {
            if (!vis[it] && detectCycleUtil(adj, it, vis, recStack))
            {
                return true;
            }
            else if (recStack[it])
            {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool detectCycle(vector<vector<int>> adj, int n)
{
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);
    for (int i = 0; i < n; i++)
    {
        if (detectCycleUtil(adj, i, visited, recStack))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    detectCycle(adj, n);
}