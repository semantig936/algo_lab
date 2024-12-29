#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int src;
    int dest;
};

class Graph
{
public: 
    vector<vector<int>> adj;
    Graph(vector<Edge> const &edges, int n)
    {
        adj.resize(n);
        vector<int> deg(n, 0);
        for(auto &edge : edges)
        {
            adj[edge.src].push_back(edge.dest);
            deg[edge.src]++;
        }
    }
};

void topological_sort()
{
    
}

int main()
{
    int n, e;
    cout<<"Enter the number of vertices and the number of edges: ";
    cin>>n>>e;
    vector<Edge> edges(n);
    cout<<"Enter the edges one by one: ";
    for(int i=0; i<e; i++)
    {
        cin>>edges[i].src>>edges[i].dest;
    }
    Graph g(edges, n);
}