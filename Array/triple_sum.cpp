#include <bits/stdc++.h>
using namespace std;

vector<int> tripleSum(vector<int> &v, int target)
{
    int n = v.size();
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            if ((v[i] + v[l] + v[r]) == target)
            {
                return {i, l, r};
            }
            else if ((v[i] + v[l] + v[r]) > target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    return {};
}

vector<vector<int>> sum3(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int low = i + 1;
            int high = n - 1;
            int sum = 0 - nums[i];
            while (low < high)
            {
                if (nums[low] + nums[high] == sum)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    res.push_back(temp);
                    while (low < high && nums[low] == nums[low + 1])
                        low++;
                    while (low < high && nums[high] == nums[high - 1])
                        high--;
                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] < sum)
                    low++;
                else
                    high--;
            }
        }
    }
    return res;
}