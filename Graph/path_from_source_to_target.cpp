#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<vector<int>> &paths, vector<int> &path, int i)
{
    path.push_back(i);
    if (i == adj.size() - 1)
    {
        paths.push_back(path);
    }
    for (auto j : adj[i])
    {
        dfs(adj, paths, path, j);
    }
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> paths;
    vector<int> path;
    dfs(graph, paths, path, 0);
    return paths;
}