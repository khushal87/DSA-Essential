#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    if (intervals.size() == 0)
        return ans;
    else
    {
        sort(intervals.begin(), intervals.end());
        vector<int> curr = intervals[0];
        for (auto j : intervals)
        {
            if (j[0] <= curr[1])
            {
                curr[1] = max(curr[1], j[1]);
            }
            else
            {
                ans.push_back(curr);
                curr = j;
            }
        }
        ans.push_back(curr);
        return ans;
    }
}