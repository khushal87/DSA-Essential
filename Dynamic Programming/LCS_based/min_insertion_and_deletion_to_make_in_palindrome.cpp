#include <bits/stdc++.h>
using namespace std;

// **insertion deletion same hi hogaaa
int findLCS(string x, string y, int m, int n)
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
    return t[m][n];
}

int main()
{
    string x;
    cin >> x;
    string y = "";
    for (int i = x.length() - 1; i >= 0; i--)
    {
        y += x[i];
    }
    // **insertion deletion same hi hogaaa
    cout << x.length() - findLCS(x, y, x.length(), y.length()) << endl;
}