#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &arr, int target)
{
    if (arr.size() == 0)
        return false;
    else
    {
        int n = arr.size();
        int m = arr[0].size();
        int low = 0, high = m - 1;
        while (low < n && high >= 0)
        {
            if (arr[low][high] == target)
            {
                return true;
            }
            else if (arr[low][high] > target)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
        return false;
    }
}