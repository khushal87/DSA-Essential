#include <bits/stdc++.h>
using namespace std;

int *parent;

int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return find(parent[x]);
}

void _union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
    {
        return;
    }
    else
    {
        parent[a] = b;
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int size = edges.size();
    parent = new int[size + 1];
    for (int i = 1; i <= size; i++)
    {
        parent[i] = i;
    }
}

int main()
{
}