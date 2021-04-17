#include <bits/stdc++.h>
using namespace std;

int mergeSortUtil(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = temp[i++];
        }
        else
        {
            temp[k++] = temp[j++];
            inv_count += inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return inv_count;
}

int mergeSort(vector<int> &arr, vector<int> &temp, int left, int right)
{
    int mid, inv_count = 0;
    if (left < right)
    {
        mid = left + (right - left) / 2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += mergeSortUtil(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}