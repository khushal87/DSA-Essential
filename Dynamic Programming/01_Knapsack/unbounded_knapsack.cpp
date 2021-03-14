#include <bits/stdc++.h>
using namespace std;

int solve(int p[], int w[], int n, int cap)
{
    int t[n + 1][cap + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (w[i - 1] <= j)
            {
                t[i][j] = max(p[i - 1] + t[i][j - w[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][cap];
}

int main()
{
    int n;
    cin >> n;
    int p[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> w[i];
    }
    int cap;
    cin >> cap;
    cout << solve(p, w, n, cap) << endl;
}