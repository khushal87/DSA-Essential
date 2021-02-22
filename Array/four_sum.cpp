#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    if (nums.empty())
        return ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int tar2 = target - nums[i] - nums[j];
            int front = j + 1;
            int back = n - 1;
            while (front < back)
            {
                int twosum = nums[front] + nums[back];
                if (twosum < tar2)
                    front++;
                else if (twosum > tar2)
                    back--;
                else
                {
                    vector<int> quad;
                    quad = {nums[i], nums[j], nums[front], nums[back]};
                    ans.push_back(quad);
                    while (front < back && nums[front] == quad[2])
                        ++front;
                    while (front < back && nums[back] == quad[3])
                        --back;
                }
            }
            while (j + 1 < n && nums[j] == nums[j + 1])
                ++j;
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
            ++i;
    }
    return ans;
}