#include "bits/stdc++.h"
using namespace std;

struct Pair
{
    /* data */
    int min;
    int max;
};

Pair solve(int arr[], int n)
{
    Pair ans;
    if (n == 1)
    {
        ans.max = arr[0];
        ans.min = arr[0];
        return ans;
    }

    if (arr[0] > arr[1])
    {
        ans.max = arr[0];
        ans.min = arr[1];
    }
    else
    {
        ans.max = arr[1];
        ans.min = arr[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (arr[i] > ans.max)
        {
            ans.max = arr[i];
        }
        else if (arr[i] < ans.min)
        {
            ans.min = arr[i];
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Pair ans = solve(arr, n);
    cout << ans.min << " " << ans.max << endl;
}