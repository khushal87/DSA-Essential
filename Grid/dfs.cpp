#include <bits/stdc++.h>
using namespace std;

bool vis[1001][1001];

bool isValid(int x, int y, int N, int M)
{
    if (x < 1 || x > N || y < 1 || y > M)
    {
        return false;
    }
    if (vis[x][y] == true)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int n, int m)
{
    vis[x][y] = 1;
    cout << x << " " << y << endl;
    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i], n, m))
        {
            dfs(x + dx[i], y + dy[i], n, m);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    dfs(1, 1, n, m);
}