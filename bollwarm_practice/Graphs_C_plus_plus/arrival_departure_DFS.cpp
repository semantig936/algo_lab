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
        for(auto &edge : edges)
        {
            adj[edge.src].push_back(edge.dest);
        }
    }
};

void time_DFS(Graph g, vector<int>&arrival, vector<int> &departure, vector<bool> &visited, int u, int &time)
{
    arrival[u] = time;
    time++;
    //cout<<"Arrived at "<<u<<", arrival time is: "<<time;
    visited[u] = true;
    for(int i : g.adj[u])
    {
        if(!visited[i])
        {
            time_DFS(g, arrival, departure, visited, i, time);
        }
    }
    departure[u] = time;
    //cout<<"Leaving "<<u<<", departure time is: "<<time;
    time++;
}

int main()
{
    int n, e;
    cout<<"Enter the number of vertices and the number of edges: ";
    cin>>n>>e;
    cout<<"Keep entering the edges one by one: "<<endl;
    vector<Edge> edges(n);
    for(int i=0; i<e; i++)
    {
        cout<<(i+1)<<": ";
        cin>>edges[i].src>>edges[i].dest;
        cout<<endl;
    }
    Graph g(edges, n);
    vector<int> arrival(n);
    vector<int> departure(n);
    vector<bool> visited(n ,false);
    int t = 0;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            time_DFS(g, arrival, departure, visited, i, t);
        }
    }
    cout<<"Arrival and departure times are: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i<<": "<<arrival[i]<<" "<<departure[i]<<endl;
    }
    return 0;
}