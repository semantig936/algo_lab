#include<bits/stdc++.h>
using namespace std;

//apparently, while doing topological sort, stacks are required
//in C, it wasn't possible, but now, we can use STL

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
        for(auto &edge : edges)
        {
            adj[edge.src].push_back(edge.dest);
        }
    }
};

void topological_sort(Graph g, vector<bool>& visited, stack<int>& s, int v)
{
    visited[v] = true;
    for(int i : g.adj[v])
    {
        if(!visited[i])
        {
            topological_sort(g, visited, s, i);
        }
    }
    s.push(v);
}

int main()
{
    int n, e;
    cout<<"Enter the number of vertices and the number of edges: ";
    cin>>n>>e;
    vector<Edge> edges(e);
    cout<<"\nEnter the source destination pairs of the edges one at a time: \n";
    for(int i=0; i<e; i++)
    {
        cin>>edges[i].src>>edges[i].dest;
    }
    Graph g(edges, n); //making a graph
    vector<bool> visited(n, false);
    stack<int> s;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            topological_sort(g, visited, s, i);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}