#include <bits/stdc++.h>
using namespace std;

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int cnt = 0;
    int offsetX[4] = {0, 1, 0, -1};
    int offsetY[4] = {1, 0, -1, 0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                cnt++;
                grid[i][j] = '0';
                queue<pair<int, int>> que;
                que.push({i, j});
                while (!que.empty())
                {
                    pair<int, int> p = que.front();
                    que.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int r = p.first + offsetX[k];
                        int c = p.second + offsetY[k];
                        if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '1')
                        {
                            grid[r][c] = '0';
                            que.push({r, c});
                        }
                    }
                }
            }
        }
    }
    return cnt;
}
