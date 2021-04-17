#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    int cnt = 1;
    int can = nums[0];
    for (auto j : nums)
    {
        if (can == j)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (cnt == 0)
        {
            can = j;
            cnt = 1;
        }
    }
    cnt = 0;
    for (auto j : nums)
    {
        if (j == can)
        {
            cnt++;
        }
    }
    if (cnt > nums.size() / 2)
        return can;
    else
        return -1;
}