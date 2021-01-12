#include <bits/stdc++.h>
using namespace std;

bool validCoordinates(int x, int y, int n, int m)
{
    if (x < 0 || y < 0)
    {
        return false;
    }
    if (x >= n || y >= m)
    {
        return false;
    }
}

void bfs(int n, int m, vector<vector<int>> data, int x, int y, int color)
{
    int vis[n][m];
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> que;
    que.push({x, y});
    vis[x][y] = 1;
    while (!que.empty())
    {
        pair<int, int> coord = que.front();
        int x = coord.first;
        int y = coord.second;
        int preColor = data[x][y];
        data[x][y] = color;
        que.pop();

        if (validCoordinates(x + 1, y, n, m) && vis[x + 1][y] == 0 && data[x + 1][y] == preColor)
        {
            vis[x + 1][y] = 1;
            que.push({x + 1, y});
        }
        if (validCoordinates(x - 1, y, n, m) && vis[x - 1][y] == 0 && data[x - 1][y] == preColor)
        {
            vis[x - 1][y] = 1;
            que.push({x - 1, y});
        }
        if (validCoordinates(x, y + 1, n, m) && vis[x][y + 1] == 0 && data[x][y + 1] == preColor)
        {
            vis[x][y + 1] = 1;
            que.push({x, y + 1});
        }
        if (validCoordinates(x, y - 1, n, m) && vis[x][y - 1] == 0 && data[x][y - 1] == preColor)
        {
            vis[x][y - 1] = 1;
            que.push({x, y - 1});
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}