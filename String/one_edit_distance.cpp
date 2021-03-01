#include <bits/stdc++.h>
using namespace std;

bool solve(string x, string y)
{
    int m = x.length();
    int n = y.length();
    if (abs(m - n) > 1)
        return false;
    int count = 0;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (x[i] != y[j])
        {
            count++;
            if (count > 1)
            {
                return false;
            }
            if (m > n)
            {
                i++;
            }
            else if (m < n)
            {
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        else
        {
            i++;
            j++;
        }
    }
    return true;
}