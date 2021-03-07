#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int> &arr, int n)
{
    int max_ending = 1;
    int min_ending = 1;
    int max_so_far = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            max_ending = max_ending * arr[i];
            min_ending = min(min_ending * arr[i], 1);
            flag = 1;
        }
        else if (arr[i] == 0)
        {
            max_ending = 1;
            min_ending = 1;
        }
        else
        {
            int temp = max_ending;
            max_ending = max(min_ending * arr[i], 1);
            min_ending = temp * arr[i];
        }
        if (max_so_far < max_ending)
            max_so_far = max_ending;
    }
    if (max_ending = 0 && flag == 1)
        return 0;
    else
        return max_so_far;
}