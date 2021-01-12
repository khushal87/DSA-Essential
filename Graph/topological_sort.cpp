#include <bits/stdc++.h>
using namespace std;

void kahn(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &in, vector<int> &res, int n)
{
    priority_queue<int, vector<int>, greater<int>> qu;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            qu.push(i);
        }
    }
    while (!qu.empty())
    {
        int curr = qu.top();
        res.push_back(curr);
        qu.pop();
        for (auto j : adj[curr])
        {
            in[j]--;
            if (in[j] == 0)
            {
                qu.push(j);
            }
        }
    }
    if (res.size() == n)
    {
        for (auto j : res)
        {
            cout << j << " ";
        }
    }
    else
    {
        cout << "Sandro fails." << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    vector<int> in(n + 1, 0);
    vector<int> res;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }
    kahn(adj, vis, in, res, n);
}