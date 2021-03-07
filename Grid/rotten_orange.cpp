#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int r, int c)
{
    if (i >= 0 && i < r && j >= 0 && j < c)
        return true;
    else
        return false;
}

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

int orangesRotting(vector<vector<int>> &arr)
{
    int r = arr.size();
    int c = arr[0].size();
    queue<pair<int, int>> qu;
    int ones = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 2)
            {
                qu.push({i, j});
            }
            if (arr[i][j] == 1)
                ones++;
        }
    }
    if (qu.empty())
    {
        if (ones == 0)
            return 0;
        else
            return -1;
    }
    int cnt = -1;
    while (!qu.empty())
    {
        cnt++;
        int sz = qu.size();
        for (int i = 0; i < sz; i++)
        {
            pair<int, int> tmp = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++)
            {
                int x_dir = tmp.first + x[i];
                int y_dir = tmp.second + y[i];
                if (isValid(x_dir, y_dir, r, c) && arr[x_dir][y_dir] == 1)
                {
                    arr[x_dir][y_dir] = 2;
                    qu.push({x_dir, y_dir});
                }
            }
        }
    }
    int flag = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 1)
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
        return -1;
    else
        return cnt;
}