#include <bits/stdc++.h>
using namespace std;

struct edge
{
    /* data */
    int a;
    int b;
    int w;
};

bool comp(edge a, edge b)
{
    return b.w > a.w;
}

int _find(vector<int> &par, int a)
{
    if (par[a] == -1)
    {
        return a;
    }
    else
    {
        return par[a] = _find(par, par[a]);
    }
}

void _union(vector<int> &par, int a, int b)
{
    par[a] = b;
}

int main()
{
    edge arr[100000];
    int n, m, a, b, w;
    cin >> n >> m;
    vector<int> par(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].w;
    }
    sort(arr, arr + m, comp);
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        a = _find(par, arr[i].a);
        b = _find(par, arr[i].b);

        if (a != b)
        {
            sum += arr[i].w;
            _union(par, a, b);
        }
    }
    cout << sum << endl;
}