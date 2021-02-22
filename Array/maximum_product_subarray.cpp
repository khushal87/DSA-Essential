#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll maxProduct(int arr[], int n)
{
    ll max_so_far = LONG_LONG_MIN;
    ll max_ending_here = 1;
    for (int i = 0; i < n; i++)
    {
        max_ending_here *= arr[i];
        if (max_ending_here > max_so_far)
        {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = abs(max_ending_here);
        }
        cout << max_ending_here << " ";
    }
    return max_so_far;
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
    cout << maxProduct(arr, n) << endl;
}