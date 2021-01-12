#include <bits/stdc++.h>
using namespace std;

int maxD, maxNode;

void dfsUtil(vector<vector<int>> &adj, vector<bool> &vis, int i, int d)
{
    vis[i] = true;
    if (d > maxD)
    {
        maxD = d;
        maxNode = i;
    }
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            dfsUtil(adj, vis, j, d + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    maxD = -1;
    dfsUtil(adj, vis, 1, 0);
    for (int i = 0; i < n + 1; i++)
    {
        vis[i] = false;
    }
    maxD = -1;
    dfsUtil(adj, vis, maxNode, 0);
    cout << maxD << endl;
}