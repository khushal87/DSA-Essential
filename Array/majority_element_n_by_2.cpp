#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr, int n)
{
    int count = 0;
    int candidate = 0;
    for (auto j : arr)
    {
        if (count == 0)
        {
            candidate = j;
        }
        if (candidate == j)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}