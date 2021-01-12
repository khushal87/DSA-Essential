#include <bits/stdc++.h>
using namespace std;

int maxPower(string s)
{
    int sz = s.length();
    if (sz == 0)
    {
        return 0;
    }
    vector<char> v;
    v.push_back(s[0]);
    vector<int> ans;
    int ctr = 1;
    if (s[0] == s[1])
    {
        ctr++;
    }
    else
    {
        ans.push_back(ctr);
    }
    for (int i = 1; i < sz - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            ctr++;
        }
        else
        {
            ans.push_back(ctr);
            ctr = 1;
        }
    }
    ans.push_back(ctr);
    return *max_element(ans.begin(), ans.end());
}

int main()
{
    string s;
    cin >> s;
    cout << maxPower(s) << endl;
}