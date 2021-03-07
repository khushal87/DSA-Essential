#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, int s)
{

    // Your code here
    int l = 0, sum = arr[0];
    for (int i = 1; i <= n; i++)
    {
        while (sum > s)
        {
            sum -= arr[l];
            l++;
        }
        if (sum == s)
        {
            vector<int> ans = {l + 1, i};
            return ans;
        }
        if (i < n)
            sum += arr[i];
    }
    return {-1};
}

vector<int> findSubarray(int a[], int n)
{
    // code here
    vector<int> ans, temp;
    int sum = 0, mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            temp.push_back(a[i]);
            sum += a[i];
        }
        if (sum >= mx)
        {
            ans = temp;
            mx = sum;
        }
        if (a[i] < 0)
        {
            temp = {};
            sum = 0;
        }
    }
    if (ans.size() > 0)
    {
        return ans;
    }
    else
        return {-1};
}