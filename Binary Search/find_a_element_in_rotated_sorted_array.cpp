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

int pivotIdx(vector<int> &arr, int n)
{
    if (arr[0] < arr[n - 1])
        return 0;
    else
    {
        int piv = -1;
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            if (arr[start] <= arr[end])
                return start;
            int mid = start + (end - start) / 2;

            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;
            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
            {
                piv = mid;
                break;
            }
            //jo side unsorted hai uss side jayenge
            if (arr[start] <= arr[mid])
            {
                start = mid + 1;
            }
            else if (arr[mid] <= arr[end])
            {
                end = mid - 1;
            }
        }
        return piv;
    }
}

int solve(vector<int> &arr, int n, int el)
{
    int n = arr.size();
    int pdx = pivotIdx(arr, n);
    int idx1 = ascBinarySearch(arr, n, 0, pdx - 1, el);
    int idx2 = ascBinarySearch(arr, n, pdx, n - 1, el);
    if (idx1 == -1 && idx2 == -1)
        return -1;
    else
    {
        if (idx1 == -1)
        {
            return idx2;
        }
        else
        {
            return idx1;
        }
    }
}