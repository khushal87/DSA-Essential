#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    bool t[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
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
                if (arr[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
    }
    vector<int> temp;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (t[n][i])
        {
            temp.push_back(i);
        }
    }
    int minm = INT_MAX;
    for (auto j : temp)
    {
        minm = min(minm, sum - 2 * j);
    }
    return minm;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr, n) << endl;
}