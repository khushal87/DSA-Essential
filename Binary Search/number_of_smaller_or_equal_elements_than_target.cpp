#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int n, int el)
{
    int start = 0;
    int end = n - 1;
    int res = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= el)
        {
            res = mid + 1;
            start = mid + 1;
        }
        else if (arr[mid] > el)
        {
            end = mid - 1;
        }
    }
    return res;
}