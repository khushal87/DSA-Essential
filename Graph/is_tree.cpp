#include <bits/stdc++.h>
using namespace std;

// a graph is a tree if there is no cycle and the graph is fully connected
bool cyclePresentOrNot(vector<vector<int>> &adj, vector<bool> &vis, int src, int parent)
{
    vis[src] = true;
    for (auto j : adj[src])
    {
        if (!vis[j])
        {
            if (cyclePresentOrNot(adj, vis, j, src))
            {
                return true;
            }
        }
        else if (j != parent)
        {
            return true;
        }
    }
    return false;
}

bool checkIfTree(vector<vector<int>> &adj)
{
    int sz = adj.size();
    vector<bool> vis(sz, false);
    if (cyclePresentOrNot(adj, vis, 0, -1))
    {
        return false;
    }
    int flag = 0;
    for (auto j : vis)
    {
        if (!j)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        return false;
    else
        return true;
}