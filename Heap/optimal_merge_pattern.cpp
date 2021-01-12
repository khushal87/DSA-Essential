#include <bits/stdc++.h>
using namespace std;

int optimalMergeCost(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (pq.size() >= 2)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        sum += (first + second);
        pq.push(first + second);
    }
    return sum;
}