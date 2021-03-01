#include <bits/stdc++.h>
using namespace std;

struct item
{
    int row, col, weight;
};

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (grid[0][0] == 1)
        return -1;
    else if (grid[n - 1][m - 1] == 1)
        return -1;
    else
    {
        item src;
        src.row = 0, src.col = 0, src.weight = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    vis[i][j] = true;
                }
                else
                {
                    vis[i][j] = false;
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
            cout << temp.row << " " << temp.col << " " << temp.weight << endl;
            if (temp.row == n - 1 && temp.col == m - 1)
            {
                return temp.weight + 1;
            }
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

            // up left
            if (temp.row - 1 >= 0 && temp.col - 1 >= 0 && vis[temp.row - 1][temp.col - 1] == false)
            {
                qu.push({temp.row - 1, temp.col - 1, temp.weight + 1});
                vis[temp.row - 1][temp.col - 1] = true;
            }

            // up right
            if (temp.row - 1 >= 0 && temp.col + 1 <= m - 1 && vis[temp.row - 1][temp.col + 1] == false)
            {
                qu.push({temp.row - 1, temp.col + 1, temp.weight + 1});
                vis[temp.row - 1][temp.col + 1] = true;
            }

            // down left
            if (temp.row + 1 <= n - 1 && temp.col - 1 >= 0 && vis[temp.row + 1][temp.col - 1] == false)
            {
                qu.push({temp.row + 1, temp.col - 1, temp.weight + 1});
                vis[temp.row + 1][temp.col - 1] = true;
            }

            // down right
            if (temp.row + 1 <= n - 1 && temp.col + 1 <= m - 1 && vis[temp.row + 1][temp.col + 1] == false)
            {
                qu.push({temp.row + 1, temp.col + 1, temp.weight + 1});
                vis[temp.row + 1][temp.col + 1] = true;
            }
        }
        return -1;
    }
}
