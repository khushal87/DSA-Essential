#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &arr, int n, int el)
{
    int start = 0;
    int end = n - 1;
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == el)
        {
            end = mid - 1;
        }
        else if (arr[mid] < el)
        {
            res = mid;
            start = mid + 1;
        }
        else if (arr[mid] > el)
        {
            end = mid - 1;
        }
    }
    return res;
}

int searchInsertK(vector<int> Arr, int N, int k)
{
    int ans = findFloor(Arr, N, k);
    return ans + 1;
}