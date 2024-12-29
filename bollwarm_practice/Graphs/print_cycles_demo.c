#include<stdio.h>
#include<stdlib.h>

//whatever the problem is, it isn't getting into an infinite loop
void printCycles(int** cycles, int* ind, int count)
{
    for(int i=0; i<count; i++)
    {
        for(int j=ind[i]-2; j>=0; j--)
        {
            printf("%d->",cycles[i][j]);
        }
        printf("%d\n",cycles[i][ind[i]-1]);                                                    
        //printf("\n");
    }
}

void dfs(int** adj, int* deg, int n, int u, int p, int* colour, int* parent, int* c, int* ind, int** cycles)
{
    //printf("\nHi!- entered the dfs function, u=%d",u);
    if(colour[u] == 2)
    {
        return;
    }
    //printf("\nHi!Statement was false so we're still in the function.");
    if(colour[u] == 1)
    {
        int* v = (int*)malloc(n*sizeof(int));
        int count = 0;
        v[count++] = p;
        int cur = p;
        while(cur != u)
        {
            cur = parent[cur];
            v[count++] = cur;
        }
        v[count++] = u;
        ind[*c] = count;
        cycles[*c] = v;
        (*c)++;
        return;
    }
    //printf("\nHi! another statement was false");
    parent[u] = p;
    colour[u] = 1; //partially visited
    for(int i=0; i<deg[u]; i++)
    {
        //printf("calling the function recursively for %d",adj[u][i]);
        dfs(adj, deg, n, adj[u][i], u, colour, parent, c, ind, cycles);
    }
    colour[u] = 2; //completely visited
}

int main()
{
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&n);
    int* deg = (int*)malloc(n*sizeof(int));
    printf("Enter the degree of each node of the graph: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&deg[i]);
    }
    int** adj = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        adj[i] = (int*)malloc(deg[i]*sizeof(int));
    }
    printf("Enter all the connected vertices of each of the vertices: ");
    for(int i=0; i<n; i++)
    {
        printf("\ni=%d: ",i);
        for(int j=0; j<deg[i]; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    int** cycles = (int**)malloc(n*sizeof(int*));// to store the cycles in the form of an n*n matrix
    for(int i=0; i<n; i++)
    {
        cycles[i] = (int*)malloc(n*sizeof(int)); 
    }
    int count = 0;//for the count of the total number of cycles
    int* ind = (int*)malloc(n*sizeof(int));//an array to store the total no. of elements in the ith cycle
    int* colour = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        colour[i] = 0; // all vertices are unvisited to begin with
    }
    int* parent = (int*)malloc(n*sizeof(int));
    //initially do the function call by making 1 the parent of 0
    dfs(adj, deg, n, 1, 0, colour, parent, &count, ind, cycles);
    /*for(int i=0; i<count; i++)
    {
        for(int j=0; j<ind[i]; j++)
        {
            printf("%d ",cycles[i][j]);
        }
        printf("\n");
    }*/
    printCycles(cycles, ind, count);
    return 0;
}