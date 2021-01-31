#include <bits/stdc++.h>
using namespace std;

vector<int> miss, dup;
void swapSort(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] != arr[arr[i] - 1])
        {
            swap(arr[i], arr[arr[i] - 1]);
        }
        else
        {
            i++;
        }
    }
}

void solve(int arr[], int n)
{
    swapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1)
        {
            miss.push_back(i + 1);
        }
        else
        {
            dup.push_back(arr[i]);
        }
    }
}