#include <bits/stdc++.h>
using namespace std;

bool rearrangeString(string str)
{
    //code here
    priority_queue<pair<int, char>> pq;
    unordered_map<char, int> mp;
    for (auto j : str)
    {
        mp[j]++;
    }
    for (auto j : mp)
    {
        pq.push({j.second, j.first});
    }
    string ans = "";
    pair<int, char> prev = make_pair(-1, '#');
    while (!pq.empty())
    {
        pair<int, char> tmp = pq.top();
        ans += tmp.second;
        tmp.first -= 1;
        pq.pop();
        if (prev.first > 0)
        {
            pq.push(prev);
        }
        prev = tmp;
    }
    if (ans.length() == str.length())
        return true;
    else
        return false;
}