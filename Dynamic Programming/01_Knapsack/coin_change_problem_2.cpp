//minimum number of coin to get a sum
#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int sum)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i <= sum; i++)
    {
        t[0][i] = INT_MAX - 1;
    }
    for (int i = 1; i <= n; i++)
    {
        t[i][0] = 0;
    }
    for (int i = 1; i <= sum; i++)
    {
        if (i % arr[0] == 0)
        {
            t[1][i] = i / arr[0];
        }
        else
        {
            t[1][i] = INT_MAX - 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = min(1 + t[i][j - arr[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
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