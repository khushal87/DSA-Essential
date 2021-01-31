#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[], int n, int k, int mx)
{
    int stud = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mx)
        {
            stud++;
            sum = arr[i];
        }
        if (stud > k)
            return false;
    }
    return true;
}

int allocateMinNumberOfPage(int arr[], int n, int k)
{
    if (n < k)
        return -1;
    int start = *max_element(arr, arr + n);
    int end = accumulate(arr, arr + n, 0);
    int result = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(arr, n, k, mid))
        {
            result = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}