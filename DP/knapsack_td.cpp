#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> wt, vector<int> val, int w, int n, vector<vector<int>>& t){
	if(t[n][w]!=-1){
		return t[n][w];
	}
	if(wt[n-1]<=w){
		return t[n][w] = max(val[n-1]+t[n-1][w-wt[n-1]], t[n-1][w]);

		// return t[n][w] = max( val[n-1]+solve(wt, val, w-wt[n-1], n-1), solve(wt, val, w, n-1));
	}
	else{
		return t[n][w] = t[n-1][w];

		// return t[n][w] = solve(wt, val, w, n-1);
	}
}

int main(){
	int n = 4, w = 7;
	vector<int> wt = {1, 3, 4, 5};
	vector<int> val = {1, 4, 5, 7};
	vector<vector<int>> t(n+1, vector<int> (w+1, 0));
	cout<<t[n][w]<<"\n";
	return 0;
}