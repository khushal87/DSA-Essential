#include <bits/stdc++.h>
using namespace std;

int findElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> leftMax(n);
    leftMax[0] = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }
    int rightMin = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (leftMax[i] < arr[i] && rightMin > arr[i])
        {
            return i;
        }
        rightMin = min(rightMin, arr[i]);
    }
    return -1;
}
