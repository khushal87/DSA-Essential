#include <bits/stdc++.h>
using namespace std;

int ascBinarySearch(int arr[], int n, int el)
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
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int descBinarySearch(int arr[], int n, int el)
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

int orderAgnostic(int arr[], int n, int el)
{
    int idx;
    if (arr[0] < arr[1])
    {
        idx = ascBinarySearch(arr, n, el);
    }
    else
    {
        idx = descBinarySearch(arr, n, el);
    }
    return idx;
}