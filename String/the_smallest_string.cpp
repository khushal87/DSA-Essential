/**
    You are given a string S which consists of lower case Latin letters and you need to perform the following operation exactly times:
    Select any character and replace it with its next character ['a' with 'b', 'b' with 'c'.... 'z' with 'a'].
    You need to find the lexicographically smallest string after performing exactly K operations on string S.
 **/

#include <bits/stdc++.h>
using namespace std;

string solve(string s, int k)
{
    int sz = s.length();
    int ref[sz];
    for (int i = 0; i < sz; i++)
    {
        int dis = s[i] - 'a';
        if (dis == 0)
            ref[i] = 0;
        else
            ref[i] = 26 - dis;
    }
    for (int i = 0; i < sz; i++)
    {
        if (k >= ref[i])
        {
            s[i] = 'a';
            k = k - ref[i];
        }
    }
    k %= 26;
    s[sz - 1] = s[sz - 1] + k;
    return s;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << solve(s, k) << endl;
    }
}