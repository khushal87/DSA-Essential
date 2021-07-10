#include <bits/stdc++.h>
using namespace std;

int solve(string s, string k)
{
    int n = s.length();
    int i = 0;
    int j = 0;
    map<char, int> mp;
    for (auto j : k)
    {
        mp[j]++;
    }
    int count = mp.size();
    int mx = INT_MAX;
    while (j < n)
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
            {
                count--;
            }
        }
        if (count > 0)
        {
        }
        else if (count == 0)
        {
        }
        else
        {
        }
    }
}