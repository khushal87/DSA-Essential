#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int src, des, weight;
    edge() {}
    edge(int s, int d, int w) : src(s), des(d), weight(w){};
};

class compare
{
public:
    bool operator()(const edge &a, const edge &b)
    {
        return a.weight < b.weight;
    }
};

vector<edge>
primsAlgorithm(vector<list<pair<int, int>>> graph, edge minEdge)
{
    vector<edge> spanningTree;
    priority_queue<edge, vector<edge>, compare> pq;
    while (spanningTree.size() == graph.size() - 1)
    {
        spanningTree.push_back(minEdge);
        for (auto it : graph[minEdge.src])
        {
            pq.push(edge(minEdge.src, it.first, it.second));
        }
        for (auto it : graph[minEdge.des])
        {
            pq.push(edge(minEdge.des, it.first, it.second));
        }
        minEdge = pq.top();
        pq.pop();
    }
    return spanningTree;
}

int main()
{
    vector<list<pair<int, int>>> graph;
    int v, e, src, des, weight;
    cin >> v >> e;
    graph.resize(v);
    edge minEdge;
    minEdge.weight = INT_MAX;
    while (e--)
    {
        cin >> src >> des >> weight;
        graph[src].push_back(make_pair(des, weight));
        graph[des].push_back(make_pair(src, weight));
        if (weight < minEdge.weight)
        {
            minEdge.src = src, minEdge.des = des, minEdge.weight = weight;
        }
    }
    vector<edge> spanningTree = primsAlgorithm(graph, minEdge);
    for (edge x : spanningTree)
    {
        cout << x.src << " " << x.des << " " << x.weight << endl;
    }
    return 0;
}