#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> graph)
{
    for (int k = 0; k < graph.size(); k++)
    {
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph.size(); j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main()
{
    vector<vector<int>> adj;
    int v, e, src, des, weight;
    cin >> v >> e;
    adj.resize(v, vector<int>(v, 0));
    while (e--)
    {
        cin >> src >> des >> weight;
        adj[src][des] = weight;
    }
    floydWarshall(adj);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << adj[i][j] << " ";
        }
    }
    cout << endl;
}