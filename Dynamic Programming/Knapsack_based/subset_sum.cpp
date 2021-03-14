#include <bits/stdc++.h>
using namespace std;

bool solve(int p[], int n, int cap)
{
    bool t[n + 1][cap + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            if (j == 0)
            {
                t[i][j] = true;
            }
            else if (i == 0 && j > 0)
            {
                t[i][j] = false;
            }
            else
            {
                if (p[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j - p[i - 1]] || t[i - 1][j];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
    }
    return t[n][cap];
}

int main()
{
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int cap;
    cin >> cap;
    cout << solve(p, n, cap) << endl;
}