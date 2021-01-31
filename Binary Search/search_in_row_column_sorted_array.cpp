#include <bits/stdc++.h>
using namespace std;

pair<int, int> index(vector<vector<int>> &arr, int n, int m, int el)
{
    int i = 0;
    int j = m - 1;
    while ((i >= 0 && i < n) && (j >= 0 && j < m))
    {
        if (arr[i][j] == el)
        {
            return {i, j};
        }
        else if (arr[i][j] > el)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return {-1, -1};
}