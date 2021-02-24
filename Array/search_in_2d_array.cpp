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
        int low = 0, high = (n * m) - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid / m][mid % m] == target)
                return true;
            else if (arr[mid / m][mid % m] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }
}