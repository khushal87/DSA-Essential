#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> s, int k)
{
    int n = s.size();
    int i = 0;
    int j = 0;
    map<string, int> mp;
    int mx = INT_MIN;
    while (j < n)
    {
        mp[s[j]]++;
        if (mp.size() < 2)
        {
            j++;
        }
        else if (mp.size() == 2)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else
        {
            while (mp.size() > 2)
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