#include <bits/stdc++.h>
using namespace std;

int _find(vector<int> &par, int x)
{
    if (par[x] < 0)
    {
        return x;
    }
    else
    {
        int y = _find(par, par[x]);
        par[x] = y;
        return y;
    }
}

void _union(vector<int> &par, int x, int y)
{
    par[x] += par[y];
    par[y] = x;
}

int main()
{
    int n;
    int e;
    cin >> n >> e;
    vector<int> par(n + 1, -1);
    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        a = _find(par, a);
        b = _find(par, b);
        if (a != b)
        {
            _union(par, a, b);
        }
    }
    long long int ans = 1;
    for (auto j : par)
    {
        if (j < 0)
        {
            ans *= abs(j);
        }
    }
    cout << ans << endl;
}