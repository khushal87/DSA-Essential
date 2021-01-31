#include <bits/stdc++.h>
using namespace std;

pair<int, int> getNearest(int arr[], int n, int el)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == el)
        {
            return {arr[mid], arr[mid]};
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
    return {arr[start], arr[end]};
}

int solve(int arr[], int n, int el)
{
    pair<int, int> pt = getNearest(arr, n, el);
    if (pt.first == pt.second)
    {
        return pt.first;
    }
    else
    {
        int temp1 = abs(pt.first - el);
        int temp2 = abs(pt.second - el);
        if (temp1 > temp2)
        {
            return pt.second;
        }
        else
        {
            return pt.first;
        }
    }
}