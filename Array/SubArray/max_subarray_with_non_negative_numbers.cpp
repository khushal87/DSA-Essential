#include <bits/stdc++.h>
using namespace std;

vector<int> findSubarray(int a[], int n)
{
    // code here
    vector<int> ans, temp;
    int sum = -1, mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            temp.push_back(a[i]);
            sum += a[i];
        }
        else
        {
            if (sum > mx)
            {
                ans = temp;
                mx = sum;
            }
            temp.clear();
            sum = 0;
        }
    }
    if (sum > mx)
    {
        ans = temp;
        mx = sum;
    }
    if (ans.size() > 0)
    {
        return ans;
    }
    else
        return {-1};
}