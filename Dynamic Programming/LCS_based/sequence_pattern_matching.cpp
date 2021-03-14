#include <bits/stdc++.h>
using namespace std;

bool findLCS(string x, string y, int m, int n)
{
    int t[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    if (y.length() == t[m][n])
        return true;
    else
        return false;
}

int main()
{
    string x, y;
    cin >> x >> y;
    cout << findLCS(x, y, x.length(), y.length()) << endl;
}