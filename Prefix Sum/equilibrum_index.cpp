#include <bits/stdc++.h>
using namespace std;

int reqIndex(vector<int> &nums, int n)
{
    int leftSum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];
    for (int i = 0; i < n; i++)
    {
        sum -= nums[i];
        if (sum == leftSum)
            return i;
        leftSum += nums[i];
    }
    return -1;
}