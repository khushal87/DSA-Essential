#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &subtree, int i)
{
    vis[i] = true;
    int curr = 1;
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            curr += dfs(adj, vis, subtree, j);
        }
    }
    subtree[i] = curr;
    return curr;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<bool> vis(n + 1, false);
    vector<vector<int>> adj(n + 1);
    vector<int> subtree(n + 1, 0);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(adj, vis, subtree, 1);
    for (int i = 1; i < n + 1; i++)
    {
        cout << subtree[i] << " ";
    }
    cout << endl;
}