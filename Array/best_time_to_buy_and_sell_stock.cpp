#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr, int n)
{
    int sum = 0, mx = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        sum += arr[i] - arr[i - 1];
        if (sum > mx)
            mx = sum;
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return mx;
}