#include <bits/stdc++.h>
using namespace std;

int pivotIdx(int arr[], int n)
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