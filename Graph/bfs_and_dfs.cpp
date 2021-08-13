// BFS and DFS

#include<bits/stdc++.h>
using namespace std;
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v) {
	for (i=1;i<=n;i++)
	  if(a[v][i] && !visited[i])
	   q[++r]=i;
	if(f<=r) {
		visited[q[f]]=1;
		bfs(q[f++]);
	}
}
void DFS(int i)
{
    int j;
	cout<<i<<" ";
    visited[i]=1;
	for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
}

int main()
{
	// for bfs
	int n,v;
	cout<<"\nEnter the number of vertices:";
	cin>>n;
	for (i=1;i<=n;i++) {
		q[i]=0;
		visited[i]=0;
	}
	cout<<"\nEnter graph data in matrix form:\n";
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   cin>>a[i][j];
	cout<<"\nEnter the starting vertex:";
	cin>>v;
	bfs(v);
	cout<<"\nThe node which are reachable are:\n";
	for (i=1;i<=n;i++)
	  if(visited[i])
	   cout<<i<<" ";
	  else
	   cout<<"\n Bfs is not possible";
	// for dfs
	int i,j;
    cout<<"Enter number of vertices:";
	cin>>n;
    cout<<"Enter adjecency matrix of the graph:\n";
  	for(i=0;i<n;i++)
       for(j=0;j<n;j++)
			cin>>G[i][j];
   for(i=0;i<n;i++)
        visited[i]=0;
    DFS(0);
	return 0;
}
