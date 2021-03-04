#include <bits/stdc++.h>
using namespace std;

int longestUnique(string s)
{
    int n = s.length();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        vector<bool> vis(256);
        for (int j = i; j < n; j++)
        {
            if (vis[s[j]] == true)
                break;
            else
            {
                res = max(res, j - i + 1);
                vis[s[j]] = true;
            }
        }
        vis[s[i]] = false;
    }
    return res;
}