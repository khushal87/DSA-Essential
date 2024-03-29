#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
const int maxN = 10;
int level[1001], LCA[1001][maxN + 1];

void dfs(int node, int lvl, int par)
{
    level[node] = lvl;
    LCA[node][0] = par;
    for (int child : adj[node])
    {
        if (child != par)
        {
            dfs(child, lvl + 1, node);
        }
    }
}

void init(int n)
{
    dfs(1, 0, -1);
    for (int i = 1; i <= maxN; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (LCA[j][i - 1] != -1)
            {
                int par = LCA[i][j - 1];
                LCA[j][i] = LCA[par][i - 1];
            }
        }
    }
}

int getLCA(int a, int b)
{
    if (level[b] < level[a])
    {
        swap(a, b);
    }
    int d = level[b] - level[a];
    while (d > 0)
    {
        int i = log2(d);
        b = LCA[b][i];
        d -= 1 << i;
    }
    if (a == b)
    {
        return a;
    }
    for (int i = maxN; i >= 0; i--)
    {
        if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
        {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    return LCA[a][0];
}

int getDistance(int a, int b)
{
    int lca = getLCA(a, b);
    return level[a] + level[b] - 2 * level[lca];
}

int main()
{
    int n, a, b, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxN; j++)
        {
            LCA[i][j] = -1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init(n);
    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        cout << getDistance(a, b) << endl;
    }
}