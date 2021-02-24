#include <bits/stdc++.h>
using namespace std;

void fillPrefixSum(vector<int> &nums, int n)
{
    vector<int> prefix(n);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }
}