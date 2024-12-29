#include<bits/stdc++.h>
using namespace std;

//I'm assuming a connected graph

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

void BFS(Graph g, int n, int u, vector<bool> visited)
{
    queue<int> q;
    visited[u] = true;
    q.push(u);
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        cout<<s<<" ";
        for(int i : g.adjList[s])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

//actually like pointers in C, writing & before variables makes the changes permanent
void BFS_recursive(Graph const &g, queue<int> &q, int n, vector<bool> &visited)
{
    
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
    queue<int> q;
    BFS_recursive(g, q, n, visited);
    return 0;
}