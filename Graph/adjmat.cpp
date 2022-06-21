//Graph Representation Adjacency Matrix

#include <bits/stdc++.h>
using namespace std;
int main(){
	int m,n;	//Number of vertices and edges;
	cin>>m>>n;
	vector<vector<int>> adj(m+1, vector<int> (m+1,0));
	for(int i=0; i<n; i++){
		int u,v;	//Vertices connected by edge
		cin>>u>>v;
		adj[u][v]=1;
		adj[v][u]=1;
	}
	return 0;
}