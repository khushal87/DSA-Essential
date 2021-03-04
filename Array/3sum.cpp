#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int l, r;
    int n = nums.size();
    set<vector<int>> ans;
    for (int i = 0; i < n - 2; i++)
    {
        l = i + 1;
        r = n - 1;
        while (l < r)
        {
            if ((nums[l] + nums[r] + nums[i]) == 0)
            {
                vector<int> temp = {nums[i], nums[l], nums[r]};
                ans.insert(temp);
                l++;
            }
            else if ((nums[l] + nums[r] + nums[i]) < 0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    vector<vector<int>> fin;
    for (auto j : ans)
        fin.push_back(j);
    return fin;
}

vector<vector<int>> method2(vector<int> nums, int target)
{
    int sz = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < sz - 2; i++)
    {
        unordered_set<int> st;
        int curr = target - nums[i];
        for (int j = i + 1; j < sz; j++)
        {
            if (st.find(curr - nums[j]) != st.end())
            {
                ans.push_back({nums[i], nums[j], curr - nums[j]});
            }
            st.insert(nums[j]);
        }
    }
}