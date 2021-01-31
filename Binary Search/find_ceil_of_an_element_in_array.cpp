#include <bits/stdc++.h>
using namespace std;

int findCeil(int arr[], int n, int el)
{
    int start = 0;
    int end = n - 1;
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == el)
        {
            return arr[mid];
        }
        else if (arr[mid] < el)
        {
            start = mid + 1;
        }
        else if (arr[mid] > el)
        {
            res = arr[mid];
            end = mid - 1;
        }
    }
    return res;
}