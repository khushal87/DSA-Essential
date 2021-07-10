#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> nums, int k)
{
    int n = nums.size();
    queue<int> qu;
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (j < n)
    {
        if (nums[j] < 0)
        {
            qu.push(nums[j]);
        }
        if ((j - i + 1) < k)
        {
            j++;
        }
        else if ((j - i + 1) == k)
        {
            if (qu.size() == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(qu.front());
                if (nums[i] == qu.front())
                {
                    qu.pop();
                }
            }
            i++;
            j++;
        }
    }
}