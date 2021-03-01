#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> v)
{
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> path(n, vector<int>(m, 0));
    if (v[0][0] == 0)
    {
        path[0][0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] == 0)
            path[i][0] = path[i - 1][0];
    }
    for (int i = 1; i < m; i++)
    {
        if (v[0][i] == 0)
            path[0][i] = path[0][i - 1];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }
    }
    return path[n - 1][m - 1];
}