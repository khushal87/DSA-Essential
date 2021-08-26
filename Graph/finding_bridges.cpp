#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &in, vector<int> &low, int timer, int i, int par)
{
    vis[i] = true;
    in[i] = low[i] = timer;
    timer++;
    for (int j : adj[i])
    {
        if (j == par)
        {
            continue;
        }
        else
        {
            if (vis[j])
            {
                //edge node - child is back edge
                low[i] = min(low[i], in[j]);
            }
            else
            {
                //edge node - child is forward egde
                dfs(adj, vis, in, low, timer, j, par);
                if (low[j] > in[i])
                {
                    cout << i << " - " << j << " is a bridge" << endl;
                }
                low[i] = min(low[i], low[j]);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<bool> vis(n + 1, false);
    vector<int> in(n + 1), low(n + 1);
    vector<vector<int>> adj(n + 1);
    int timer;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(adj, vis, in, low, timer, 1, -1);
}