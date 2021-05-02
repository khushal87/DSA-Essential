#include <bits/stdc++.h>
using namespace std;

vector<int> getNextPermutation(vector<int> v)
{
    int n = v.size();
    int k;
    for (k = n - 2; k >= 0; k--)
    {
        if (v[k] < v[k + 1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(v.begin(), v.end());
    }
    else
    {
        int i;
        for (i = n - 1; i > k; i--)
        {
            if (v[i] > v[k])
            {
                break;
            }
        }
        swap(v[k], v[i]);
        reverse(v.begin() + k + 1, v.end());
    }
    return v;
}