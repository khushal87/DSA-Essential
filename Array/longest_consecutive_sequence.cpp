#include <bits/stdc++.h>
using namespace std;

int longestConsSeq(vector<int> nums)
{
    int n = nums.size();
    set<int> st;
    for (auto j : nums)
    {
        st.insert(j);
    }
    int mx = 0;
    for (auto j : nums)
    {
        if (!st.count(j - 1))
        {
            int curr = j;
            int ctr = 1;
            while (st.count(curr + 1))
            {
                curr += 1;
                ctr++;
            }
            mx = max(mx, ctr);
        }
    }
    return mx;
}