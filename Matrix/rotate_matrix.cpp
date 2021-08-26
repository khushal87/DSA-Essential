#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (n == 0)
        return {};
    else
    {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return matrix;
    }
}