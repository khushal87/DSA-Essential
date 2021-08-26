#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> nums, int k)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    deque<int> list;
    if (k < nums.size())
    {
        ans.push_back(*max_element(nums.begin(), nums.end()));
        return ans;
    }
    while (j < n)
    {
        while (list.size() > 0 && list.back() < nums[j])
        {
            list.pop_back();
        }
        list.push_back(nums[j]);
        if ((j - i + 1) < k)
        {
            j++;
        }
        else if ((j - i + 1) == k)
        {
            ans.push_back(list.front());
            if (list.front() == nums[i])
            {
                list.pop_front();
            }
            i++;
            j++;
        }
    }
}