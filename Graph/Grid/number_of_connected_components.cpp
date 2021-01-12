#include <bits/stdc++.h>
using namespace std;

bool vis[1001][1001];
int arr[1001][1001];

bool isValid(int x, int y, int N, int M)
{
    if (x < 1 || x > N || y < 1 || y > M)
    {
        return false;
    }
    if (vis[x][y] == true || arr[x][y] == 0)
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
    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i], n, m))
        {
            dfs(x + dx[i], y + dy[i], n, m);
        }
    }
}

int number_of_con_comp(int n, int m)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 1 && vis[i][j] == false)
            {
                cnt++;
                dfs(i, j, n, m);
            }
        }
    }
    return cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << number_of_con_comp(n, m) << endl;
}