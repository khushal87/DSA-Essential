#include <bits/stdc++.h>
using namespace std;

pair<int, int> indexes(int arr[], int n, int el)
{
    int start = 0;
    int end = 1;
    while (el > arr[end])
    {
        start = end;
        end = end * 2;
    }
    return {start, end};
}

int search(int arr[], int n, pair<int, int> indices, int el)
{
    int start = indices.first;
    int end = indices.second;
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