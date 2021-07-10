#include <bits/stdc++.h>
using namespace std;

int largestSubarray(vector<int> &nums, int target)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    int sum = 0;
    int mx = 0;
    while (j < n)
    {
        sum += nums[j];
        if (sum < target)
        {
            j++;
        }
        else if (sum == target)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else
        {
            while (sum > target)
            {
                sum -= nums[i];
                i++;
            }
            j++;
        }
    }
    return mx;
}