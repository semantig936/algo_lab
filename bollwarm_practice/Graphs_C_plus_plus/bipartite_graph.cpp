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
            adj[edge.dest].push_back(edge.src);
        }
    }    
};

void DFS(Graph g, vector<int> &colour, vector<bool> &visited, int u)
{
    cout<<"u = "<<u<<endl;
    cout<<"Colour of u = "<<colour[u]<<endl;
    visited[u] = true;
    for(int i : g.adj[u])
    {
        if(!visited[i])
        {
            if(colour[u] == 0)
            {
                colour[i] = 1;
            }
            else
            {
                colour[i] = 0;
            }
            DFS(g, colour, visited, i);
        }
    }
}

int main()
{
    int n, e;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>e;
    vector<Edge> edges(e);
    cout<<"Enter the edges one by one: "<<endl;
    for(int i=0; i<e; i++)
    {
        cout<<(i+1)<<": ";
        cin>>edges[i].src>>edges[i].dest;
    }
    Graph g(edges, n);
    for(int i=0; i<n; i++)
    {
        cout<<i<<": ";
        for(int j : g.adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    vector<bool> visited(n, false);
    vector<int> colour(n, -1);
    //colour[0] = 0;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            colour[i] = 0;
            DFS(g, colour, visited, i);
        }
    }
    cout<<"The colours are: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i<<" : "<<colour[i]<<endl;
    }
    for(auto &edge : edges)
    {
        if(colour[edge.src] == colour[edge.dest])
        {
            cout<<"Not Bipartite";
            return 0;
        }
    }
    cout<<"Bipartite";
    return 0;
}