#include "bits/stdc++.h"
using namespace std;

vector<int> v[100005];

pair<long long, int> dfs(int node)
{
    long long int mex = 0;
    int sz = 1;
    for (auto u : v[node])
    {
        auto temp = dfs(u);
        mex = max(mex, temp.first);
        sz += temp.second;
    }
    return {mex + sz, sz};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            v[i].clear();
        }
        for (int i = 2; i <= n; i++)
        {
            int x;
            cin >> x;
            v[x].push_back(i);
        }
        cout << dfs(1).first << endl;
    }
}