// You are given an array A consisting of integer values.
// Find an integer K such that the value of the following function is minimized :
// \sum_{i = 1}^{i = N} (A[i] \ XOR \ K) ,XOR represents a bitwise XOR operation
//  If multiple such K exist, then print the minimum possible value of K.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<long long> &nums, int n)
{
    auto it = max_element(nums.begin(), nums.end());
    int p = log2(*it) + 1;
    long long ans = 0;
    for (int i = 0; i < p; i++)
    {
        int ctr = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] && (1 << i))
            {
                ctr++;
            }
        }
        if (ctr > (n / 2))
        {
            ans += (1 << i);
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> arr;
        long long x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            arr.push_back(x);
        }
        cout << solve(arr, n) << endl;
    }
}