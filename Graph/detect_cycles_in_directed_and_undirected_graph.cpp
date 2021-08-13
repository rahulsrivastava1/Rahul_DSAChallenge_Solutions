// detect cycles in directed and undirected graph

#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
	bool isCyclicUtil(int v, bool visited[], bool *rs); // used by isCyclic()
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	bool isCyclic(); // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
	if(visited[v] == false)
	{
		// Mark the current node as visited and part of recursion stack
		visited[v] = true;
		recStack[v] = true;

		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
				return true;
			else if (recStack[*i])
				return true;
		}

	}
	recStack[v] = false; // remove the vertex from recursion stack
	return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
	// Mark all the vertices as not visited and not part of recursion
	// stack
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}

	// Call the recursive helper function to detect cycle in different
	// DFS trees
	for(int i = 0; i < V; i++)
		if (isCyclicUtil(i, visited, recStack))
			return true;

	return false;
}

int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	if(g.isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";
	return 0;
}
// // A C++ Program to detect
// cycle in an undirected graph
#include<bits/stdc++.h>
using namespace std;

// Class for an undirected graph
class Graph
{
	
	// No. of vertices
	int V;

	// Pointer to an array
	// containing adjacency lists
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[],
							int parent);
public:

	// Constructor
	Graph(int V);

	// To add an edge to graph
	void addEdge(int v, int w);

	// Returns true if there is a cycle
	bool isCyclic();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	
	// Add w to v’s list.
	adj[v].push_back(w);

	// Add v to w’s list.
	adj[w].push_back(v);
}

// A recursive function that
// uses visited[] and parent to detect
// cycle in subgraph reachable
// from vertex v.
bool Graph::isCyclicUtil(int v,
				bool visited[], int parent)
{
	
	// Mark the current node as visited
	visited[v] = true;

	// Recur for all the vertices
	// adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i !=
					adj[v].end(); ++i)
	{
		
		// If an adjacent vertex is not visited,
		//then recur for that adjacent
		if (!visited[*i])
		{
		if (isCyclicUtil(*i, visited, v))
			return true;
		}

		// If an adjacent vertex is visited and
		// is not parent of current vertex,
		// then there exists a cycle in the graph.
		else if (*i != parent)
		return true;
	}
	return false;
}

// Returns true if the graph contains
// a cycle, else false.
bool Graph::isCyclic()
{
	
	// Mark all the vertices as not
	// visited and not part of recursion
	// stack
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper
	// function to detect cycle in different
	// DFS trees
	for (int u = 0; u < V; u++)
	{
	
		// Don't recur for u if
		// it is already visited
		if (!visited[u])
		if (isCyclicUtil(u, visited, -1))
			return true;
	}
	return false;
}

// Driver program to test above functions
int main()
{
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.isCyclic()?
	cout << "Graph contains cycle\n":
	cout << "Graph doesn't contain cycle\n";

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.isCyclic()?
	cout << "Graph contains cycle\n":
	cout << "Graph doesn't contain cycle\n";

	return 0;
}

