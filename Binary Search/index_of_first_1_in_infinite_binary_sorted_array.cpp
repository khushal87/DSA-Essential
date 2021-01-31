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

int firstOcc(int arr[], int n, int el, pair<int, int> indices)
{
    int start = indices.first;
    int end = indices.second;
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