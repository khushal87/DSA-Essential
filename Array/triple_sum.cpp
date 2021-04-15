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