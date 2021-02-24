#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums, int n)
{
    unordered_set<int> st;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == 0 || st.find(sum) != st.end())
        {
            return true;
        }
        st.insert(sum);
    }
    return false;
}