#include <bits/stdc++.h>
using namespace std;

vector<int> printClosest(vector<int> arr1, vector<int> arr2, int x)
{
    int n = arr1.size(), m = arr2.size();
    int i = 0, j = m - 1;
    int mn = INT_MAX;
    vector<int> ans;
    int res_l, res_r;
    while (i < n && j >= 0)
    {
        if ((arr1[i] + arr2[j] - x) < mn)
        {
            res_l = i, res_r = j;
            mn = min(mn, arr1[i] + arr2[j] - x);
        }
        if ((arr1[i] + arr2[j]) > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    ans.push_back(arr1[res_l]);
    ans.push_back(arr2[res_r]);
    return ans;
}