#include <bits/stdc++.h>
using namespace std;

int solve(string s, string pat)
{
    int n = s.length();
    int i = 0;
    int j = 0;
    int k = pat.length();
    int ans = 0;
    map<char, int> mp;
    for (auto j : pat)
    {
        mp[j]++;
    }
    int count = mp.size();
    while (j < n)
    {
        // calculation
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
            {
                count--;
            }
        }

        // less than k
        if ((j - i + 1) < k)
        {
            j++;
        }
        // equal to k
        else if ((j - i + 1) == k)
        {
            if (count == 0)
            {
                ans++;
            }
            // nullify the start
            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]++;
                if (mp[s[i]] == 1)
                {
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}