#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 1, j = 0;
    int count = 1, mx = 1;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            count++;
            i++;
        }
        else if (arr[i] > dep[j])
        {
            count--;
            j++;
        }
        if (count > mx)
            mx = count;
    }
    return mx;
}