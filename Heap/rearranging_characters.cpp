#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    map<char, int> mp;
    for (auto j : s)
    {
        mp[j]++;
    }
    priority_queue<pair<int, char>> pq;

    for (auto j : mp)
    {
        pq.push({j.second, j.first});
    }
    string result = "";
}

int main()
{
    string s;
    cin >> s;
    cout << solve(s);
}