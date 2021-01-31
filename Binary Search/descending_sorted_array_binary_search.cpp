#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int el)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == el)
        {
            return mid;
        }
        else if (arr[mid] > el)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}