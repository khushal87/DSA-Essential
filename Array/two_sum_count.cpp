#include <bits/stdc++.h>
using namespace std;

int count(vector<int> &arr, int sum)
{
    int n = arr.size();
    map<int, int> mp;
    for (auto j : arr)
    {
        mp[j]++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += mp[sum - arr[i]];
        // if pair(arr[i],arr[i])
        if (sum - arr[i] == arr[i])
        {
            cnt--;
        }
    }
    return cnt / 2;
}