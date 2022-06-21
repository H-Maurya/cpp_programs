//Graph Representation Adjacency List

#include <bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	vector<int> adj[m+1];
	for(int i=0; i<n; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	return 0;
}


//For weighted graph

#include <bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	vector<pair<int,int>> adj[m+1];
	for(int i=0; i<n; i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}
	return 0;
}