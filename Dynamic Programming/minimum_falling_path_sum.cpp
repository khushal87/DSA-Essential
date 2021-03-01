#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = grid[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
            {
                dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i - 1][j + 1] + grid[i][j]);
            }
            else if (j == n - 1)
            {
                dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i - 1][j - 1] + grid[i][j]);
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1] + grid[i][j], dp[i - 1][j] + grid[i][j], dp[i - 1][j + 1] + grid[i][j]);
            }
        }
    }
    int ans = INT_MAX;
    for (auto j : dp[n - 1])
    {
        if (j < ans)
            ans = j;
    }
    return ans;
}