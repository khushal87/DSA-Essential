#include <bits/stdc++.h>
using namespace std;

int minDistance(string x, string y)
{
    int m = x.length();
    int n = y.length();
    int t[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                t[i][j] = j;
            else if (j == 0)
                t[i][j] = i;
            else if (x[i - 1] == y[j - 1])
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