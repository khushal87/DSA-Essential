#include <bits/stdc++.h>
using namespace std;

double power(double x, int n)
{
    double ans = 1.0;
    long m = n;
    if (m < 0)
    {
        m = -1 * m;
    }
    while (m > 0)
    {
        if (m % 2 == 0)
        {
            x = x * x;
            m /= 2;
        }
        else
        {
            ans = ans * x;
            m--;
        }
    }
    if (n < 0)
    {
        ans = (double)(1.0) / (double)ans;
    }
    return ans;
}