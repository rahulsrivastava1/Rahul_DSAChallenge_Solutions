// Kruskal's Algorithm

#include <bits/stdc++.h>
using namespace std;
class Edge
{
	public:
    	int src, dest, weight;
};
class Graph {
	public:
    	int V, E;
    	Edge* edge;
};
Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
class subset
{
	public:
    	int parent;
    	int rank;
};
int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent
            = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}
void KruskalMST(Graph* graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),myComp);
    subset* subsets = new subset[(V * sizeof(subset))];
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < graph->E)
    {
    	Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
	}
	cout << "Following are the edges in the constructed "
            "MST\n";
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        cout << result[i].src << " -- " << result[i].dest
             << " == " << result[i].weight << endl;
        minimumCost = minimumCost + result[i].weight;
    }
    cout << "Minimum Cost Spanning Tree: " << minimumCost
         << endl;
}

// driver code
int main()
{
	int V = 4;
    int E = 5;
    Graph* graph = createGraph(V, E);
 
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
 
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
 
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
 
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
 
    KruskalMST(graph);
    return 0;
}

// Prim's algorithm

#include<bits/stdc++.h>
// setting no. of vertices
#define V 5
// 2-D array for adjacency matrix
int G[V][V]={
	{0, 9, 75, 0, 0},
  	{9, 0, 95, 19, 42},
  	{75, 95, 0, 51, 66},
  	{0, 19, 51, 0, 31},
  	{0, 42, 66, 31, 0}
};
// driver code
int main()
{
	int n;
	int selected[V];
	// set selected false initially
	memset(selected, false, sizeof(selected));
	n=0;
	selected[0]=true;
	int row;
	int col;
	cout<<"Edge : weight\n";
	while(n<V-1)
	{
		int min=9999999;
		row=0;
		col=0;
		for(int i=0;i<V;i++)
		{
			if(selected[i])
			{
				for(int j=0;j<V;j++)
				{
					if (!selected[j] && G[i][j])
					{
						if (min > G[i][j])
						{
							min = G[i][j];
              				row = i;
              				col = j;
						}
					}
				}
			}
		}
	printf("%d - %d : %d\n",row,col,G[row][col]);
    selected[col] = true;
    n++;
	}
	return 0;
}

