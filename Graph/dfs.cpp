#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<int> adj[], vector<int> &ans){
	ans.push_back(node);
	vis[node]=1;
	for(auto it:adj[node]){
		if(!vis[it]){
			dfs(it, vis, adj, ans);
		}
	}
}

int main(){
	int m,n;		//Vertices and Edges
	cin>>m>>n;
	vector<int> adj[m+1];
	for(int i=0; i<n; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> ans;
	vector<int> vis(m+1, 0);
	for(int i=1; i<=m; i++){
		if(!vis[i]){
			dfs(i, vis, adj, ans);
		}
	} 
	for(auto it:ans){
		cout<<it<<" ";
	}
	cout<<"\n";
	return 0;
}