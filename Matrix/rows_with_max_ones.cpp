#include <bits/stdc++.h>
using namespace std;

int rowWithMax1(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (n == 0)
        return 0;
    else
    {
        int row = -1;
        int i = 0;
        int j = m - 1;
        while (i <= n && j >= 0)
        {
            if (matrix[i][j] == 1)
            {
                row = i;
                j--;
            }
            else
            {
                i++;
            }
        }
        return row;
    }
}