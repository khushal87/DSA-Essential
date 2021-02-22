#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{
    int start = 0;
    int mid = 0;
    int end = n - 1;
    while (mid <= end)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[start++], arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[end--]);
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
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
    solve(arr, n);
    cout << endl;
}