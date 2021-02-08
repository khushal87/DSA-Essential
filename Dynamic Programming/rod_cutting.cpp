//same as unbounded cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int p[], int len[], int n, int lenRod)
{
    int t[n + 1][lenRod + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= lenRod; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (len[i - 1] <= j)
            {
                t[i][j] = max(p[i - 1] + t[i][j - len[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][lenRod];
}

int main()
{
    int n;
    cin >> n;
    int p[n], len[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> len[i];
    }
    int lenRod;
    cin >> lenRod;
    cout << solve(p, len, n, lenRod) << endl;
}