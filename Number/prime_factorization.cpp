#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> primeFac(int n)
{
    vector<pair<int, int>> v;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int ctr = 0;
            while (n % i == 0)
            {
                n /= i;
                ctr++;
            }
            v.push_back({i, ctr});
        }
    }
    if (n > 1)
        v.push_back({n, 1});
    return v;
}