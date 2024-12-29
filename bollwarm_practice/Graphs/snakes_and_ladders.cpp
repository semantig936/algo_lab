#include<bits/stdc++.h>
using namespace std;
#define n 100 //this is a snake and ladder board, so size of n will be fixed

struct Edge
{
    int src;
    int dest;
};

struct Node
{
    int val;
    int dist;
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

int BFS(Graph const &g, int source)
{
    queue<Node> q;
    vector<bool> discovered()
}

int main()
{
    unordered_map<int, int> ladder, snake;

    //for the ladders - initialisation
    ladder[1] = 38;
    ladder[4] = 14;
    ladder[9] = 31;
    ladder[21] = 42;
    ladder[28] = 84;
    ladder[51] = 67;
    ladder[72] = 91;
    ladder[80] = 99;

    //for the snakes - initialisation
    snake[17] = 7;
    snake[54] = 34;
    snake[62] = 19;
    snake[64] = 60;
    snake[87] = 36;
    snake[93] = 73;
    snake[95] = 75;
    snake[98] = 79;
}

