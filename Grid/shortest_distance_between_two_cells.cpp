#include <bits/stdc++.h>
using namespace std;

struct item
{
    int row, col, weight;
};

int shortestDistance(vector<vector<char>> &grid)
{
    item src;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                vis[i][j] = true;
            }
            else
            {
                vis[i][j] = false;
            }
            if (grid[i][j] == 's')
            {
                src.row = i, src.col = j, src.weight = 0;
            }
        }
    }
    queue<item> qu;
    qu.push(src);
    vis[src.row][src.col] = true;
    while (!qu.empty())
    {
        item temp = qu.front();
        qu.pop();
        if (grid[temp.row][temp.col] == 'd')
            return temp.weight;
        // up
        if (temp.row - 1 >= 0 && vis[temp.row - 1][temp.col] == false)
        {
            qu.push({temp.row - 1, temp.col, temp.weight + 1});
            vis[temp.row - 1][temp.col] = true;
        }

        //down
        if (temp.row + 1 <= n - 1 && vis[temp.row + 1][temp.col] == false)
        {
            qu.push({temp.row + 1, temp.col, temp.weight + 1});
            vis[temp.row + 1][temp.col] = true;
        }

        // left
        if (temp.col - 1 >= 0 && vis[temp.row][temp.col - 1] == false)
        {
            qu.push({temp.row, temp.col - 1, temp.weight + 1});
            vis[temp.row][temp.col - 1] = true;
        }

        // right
        if (temp.col + 1 <= m - 1 && vis[temp.row][temp.col + 1] == false)
        {
            qu.push({temp.row, temp.col + 1, temp.weight + 1});
            vis[temp.row][temp.col + 1] = true;
        }
    }
    return -1;
}