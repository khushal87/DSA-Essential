#include <bits/stdc++.h>
using namespace std;

int numberOfPaths1(int i, int j, int n, int m)
{
    if (i == n - 1 && j == m - 1)
        return 1;
    if (i >= n || j >= m)
        return 0;
    else
        return numberOfPaths1(i + 1, j, n, m) + numberOfPaths1(i, j + 1, n, m);
}

int numberOfPaths2(int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i == n - 1 && j == m - 1)
        return 1;
    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    return dp[i][j] = numberOfPaths2(i + 1, j, n, m, dp) + numberOfPaths2(i, j + 1, n, m, dp);
}

int numberOfPaths3(int n, int m)
{
    int N = n + m - 2;
    int r = n - 1;
    double res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (N - i);
        res /= (i + 1);
    }
    return (int)res;
}
