#include <bits/stdc++.h>
using namespace std;

struct edge
{
    /* data */
    int a, b, w;
};

pair<bool, vector<int>> bellmanFord(vector<edge> graph, int vertex, int source)
{
    vector<int> distance(vertex, INT_MAX);
    distance[source] = 0;
    for (int i = 0; i < vertex - 1; i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            if (distance[graph[j].b] > distance[graph[j].a] + graph[j].w)
            {
                distance[graph[j].b] = distance[graph[j].a] + graph[j].w;
            }
        }
    }
    for (int j = 0; j < graph.size(); j++)
    {
        if (distance[graph[j].b] > distance[graph[j].a] + graph[j].w)
        {
            return make_pair(false, vector<int>());
        }
    }
    return make_pair(true, distance);
}

int main()
{
    int edges, source, vertex;
    vector<edge> graph;
    cin >> edges >> source;
    for (int i = 0; i < edges; i++)
    {
        cin >> graph[i].a >> graph[i].b >> graph[i].w;
    }
    cin >> source;
    pair<bool, vector<int>> result = bellmanFord(graph, vertex, source);
    if (result.first == true)
    {
        cout << "No cycles exists" << endl;
        for (auto it : result.second)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Graph has negative weight cycle" << endl;
    }
}