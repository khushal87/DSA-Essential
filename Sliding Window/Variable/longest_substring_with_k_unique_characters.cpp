#include <bits/stdc++.h>
using namespace std;

int solve(string s, int k)
{
    int n = s.length();
    int i = 0;
    int j = 0;
    map<char, int> mp;
    int mx = INT_MIN;
    while (j < n)
    {
        mp[s[j]]++;
        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return mx;
}