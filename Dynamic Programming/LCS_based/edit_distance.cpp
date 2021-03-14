#include <bits/stdc++.h>
using namespace std;

int minDistance(string x, string y)
{
    int m = x.length();
    int n = y.length();
    int t[m + 1][n + 1];
    t[0][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        t[i][0] = i;
    }
    for (int j = 1; j <= n; j++)
    {
        t[0][j] = j;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = 1 + min({t[i - 1][j], t[i][j - 1], t[i - 1][j - 1]});
            }
        }
    }
    return t[m][n];
}

int main()
{
    string x, y;
    cin >> x >> y;
    minDistance(x, y);
}