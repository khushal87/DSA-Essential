#include <bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int n)
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