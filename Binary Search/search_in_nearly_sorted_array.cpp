#include <bits/stdc++.h>
using namespace std;

int searchNearlySorted(int arr[], int n, int el)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == el)
            return mid;
        if (mid - 1 >= start && arr[mid - 1] == el)
            return mid - 1;
        if (mid + 1 <= end && arr[mid + 1] == el)
            return mid + 1;
        else if (arr[mid] < el)
        {
            start = mid + 2;
        }
        else if (arr[mid] > el)
        {
            end = mid - 2;
        }
    }
}