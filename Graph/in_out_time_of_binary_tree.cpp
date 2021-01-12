#include <bits/stdc++.h>
using namespace std;

int timer = 1;
void dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &in, vector<int> &out, int i)
{
    vis[i] = true;
    in[i] = timer++;
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            dfs(adj, vis, in, out, j);
        }
    }
    out[i] = timer++;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<bool> vis(n + 1, false);
    vector<vector<int>> adj(n + 1);
    vector<int> in(n + 1, -1), out(n + 1, -1);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(adj, vis, in, out, n);

    for (auto j : in)
    {
        cout << j << " ";
    }
    cout << endl;
    for (auto j : out)
    {
        cout << j << " ";
    }
    cout << endl;
}