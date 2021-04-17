#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> &matrix)
{
    bool rowFlag = false;
    bool colFlag = false;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && matrix[i][j] == 0)
                rowFlag = true;
            if (j == 0 && matrix[i][j] == 0)
                colFlag = true;
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
    if (rowFlag)
        for (int i = 0; i < m; i++)
            matrix[0][i] = 0;
    if (colFlag)
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
    return matrix;
}