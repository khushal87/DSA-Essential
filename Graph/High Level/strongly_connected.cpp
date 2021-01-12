#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

void dfsUtil(int i, vector<bool> &vis)
{
    vis[i] = true;
    cout << i << " ";
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            dfsUtil(j, vis);
        }
    }
}

void fillOrder(int i, vector<bool> &vis, stack<int> &st)
{
    vis[i] = true;
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            fillOrder(j, vis, st);
        }
    }
    st.push(i);
}

void getTranspose(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (auto j : adj[i])
        {
            adj[j].push_back(i);
        }
    }
}

void printSCS(int N)
{
    stack<int> st;
    vector<bool> vis(N, false);
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            fillOrder(i, vis, st);
        }
    }

    getTranspose(N);
    for (int i = 0; i < N; i++)
    {
        vis[i] = false;
    }
    while (st.empty() == false)
    {
        int v = st.top();
        st.pop();
        if (vis[v] == false)
        {
            dfsUtil(v, vis);
            cout << endl;
        }
    }
}