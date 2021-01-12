// Simply check if the number of connected components
// in a graph is 1 and if the number of edges is n-1

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &vis, int i)
{
    vis[i] = true;
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            dfs(adj, vis, j);
        }
    }
}

int number_of_connected_comp(vector<vector<int>> &adj, vector<bool> &vis, int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(adj, vis, i);
            count++;
        }
    }
    return count;
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
    if (number_of_connected_comp(adj, vis, n) == 1 && e == n - 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}