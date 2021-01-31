#include <bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int n, int el)
{
    int start = 0;
    int end = n - 1;
    int result = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == el)
        {
            result = mid;
            end = mid - 1;
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
    return result;
}

int lastOcc(int arr[], int n, int el)
{
    int start = 0;
    int end = n - 1;
    int result = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == el)
        {
            result = mid;
            start = mid + 1;
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
    return result;
}

int count(int arr[], int n, int el)
{
    int first = firstOcc(arr, n, el);
    int last = lastOcc(arr, n, el);
    return last - first + 1;
}