#include <bits/stdc++.h>
using namespace std;

int ascBinarySearch(vector<int> &arr, int n, int start, int end, int el)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == el)
        {
            return mid;
        }
        else if (arr[mid] < el)
        {
            return ascBinarySearch(arr, n, mid + 1, end, el);
        }
        else
        {
            return ascBinarySearch(arr, n, start, mid - 1, el);
        }
    }
    return -1;
}

int descBinarySearch(vector<int> &arr, int n, int start, int end, int el)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == el)
        {
            return mid;
        }
        else if (arr[mid] > el)
        {
            return descBinarySearch(arr, n, mid + 1, end, el);
        }
        else
        {
            return descBinarySearch(arr, n, start, mid - 1, el);
        }
    }
    return -1;
}

//same as finding peak element
int peakElement(vector<int> &arr, int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid > 0 && mid < n - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid - 1] > arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else if (mid == 0)
        {
            if (arr[mid + 1] < arr[mid])
            {
                return mid;
            }
            else
            {
                return mid + 1;
            }
        }
        else if (mid == n - 1)
        {
            if (arr[mid] > arr[mid - 1])
            {
                return mid;
            }
            else
            {
                return mid - 1;
            }
        }
    }
}

int solve(vector<int> &arr, int el)
{
    int n = arr.size();
    int pdx = peakElement(arr, n);
    int idx1 = ascBinarySearch(arr, n, 0, pdx - 1, el);
    int idx2 = descBinarySearch(arr, n, pdx, n - 1, el);
    if (idx1 == -1 && idx2 == -1)
        return -1;
    else
    {
        if (idx1 == -1)
        {
            return idx2;
        }
        if (idx2 == -1)
        {
            return idx1;
        }
    }
}
