// represent a graph in adjancey matrix and adjancey list

#include<bits/stdc++.h>
using namespace std;
class Graph
{
	private:
		bool** adjMat;
		int numVertices;
	public:
		Graph(int numVertices)
		{
			this->numVertices=numVertices;
			adjMat=new bool*[numVertices];
			for(int i=0;i<numVertices;i++)
			{
				adjMat[i]=new bool[numVertices];
				for(int j=0;j<numVertices;j++)
					adjMat[i][j]=false;
			}	
		}	
		void addEdges(int i,int j)
		{
			adjMat[i][j]=true;
			adjMat[j][i]=true;
		}
		void removeEdges(int i,int j)
		{
			adjMat[i][j]=false;
			adjMat[j][i]=false;
		}
		void printMatrix()
		{
			for(int i=0;i<numVertices;i++)
			{
				cout<<i<<":";
				for(int j=0;j<numVertices;j++)
					cout<<adjMat[i][j]<<" ";
				cout<<"\n";
			}
		}
		~Graph()
		{
			for(int i=0;i<numVertices;i++)
				delete[] adjMat[i];
			delete[] adjMat;
		}
};
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}
int main()
{
  	// Adjancey matrix
  	cout<<"Using adjancey matrix:";
  	Graph g(4);
  	g.addEdges(0, 1);
  	g.addEdges(0, 2);
  	g.addEdges(1, 2);
  	g.addEdges(2, 0);
  	g.addEdges(2, 3);
  	g.printMatrix();
  	// Adjancey list
  	cout<<"\n using adjancey list:";
  	int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
  	return 0;
}
