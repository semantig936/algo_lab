//I will assume a fully connected graph

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
    vector<vector<int>> adjList;
    Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);
        for(auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }    
};


void DFS(Graph const &g, vector<bool> &visited, int u)
{
    visited[u] = true;
    cout<<u<<" ";
    for(int i : g.adjList[u])
    {
        if(!visited[i])
        {
            DFS(g, visited, i);
        }
    }
}


int main()
{
    //input type - I'll take an array of edges from the user
    int n, e;
    cout<<"Enter the number of vertices and the number of edegs in the graph: ";
    cin>>n>>e;
    cout<<endl;
    vector<Edge> edges(e);
    cout<<"Keep entering the source and destination one by one: "<<endl;
    for(int i=0; i<e; i++)
    {
        cout<<(i+1)<<": ";
        cin>>edges[i].src>>edges[i].dest;
    }
    Graph g(edges, n);
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            DFS(g, visited, i);
        }
    }
    return 0;
}