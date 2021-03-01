#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &ranges)
{
    int maxi = -1;
    for (auto j : ranges)
    {
        if (j[1] > maxi)
        {
            maxi = j[1];
        }
    }
    vector<int> arr(maxi + 1, 0);
    for (auto j : ranges)
    {
        arr[j[0]] += 1;
        arr[j[1] + 1] -= 1;
    }
    vector<int> prefix(maxi + 1);
    int ans = arr[0], ind = 0;

    for (int i = 1; i <= maxi; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
        if (prefix[i] > ans)
        {
            ans = prefix[i];
            ind = i;
        }
    }
    return ind;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }
    cout << solve(arr);
}