#include <bits/stdc++.h>
using namespace std;

void findFirstNonRepeating(string s)
{
    int sz = s.length();
    queue<char> qu;
    vector<int> count(26, 0);
    for (int i = 0; i < sz; i++)
    {
        qu.push(s[i]);
        count[s[i] - 'a']++;
        while (!qu.empty())
        {
            if (count[qu.front() - 'a'] > 1)
            {
                qu.pop();
            }
            else
            {
                cout << qu.front() << " ";
                break;
            }
        }
        if (qu.empty())
        {
            cout << -1 << endl;
        }
    }
}