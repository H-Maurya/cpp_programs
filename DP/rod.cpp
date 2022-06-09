//Rod cutting problem

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> l, vector<int> p, int n, vector<vector<int>> &t){
	for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++){
			if(l[i-1]<=j){
				t[i][j] = max(p[i-1]+t[i][j-l[i-1]], t[i-1][j]);
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][n];
}

int main(){
	int n = 8;
	vector<int> l = {1,2,3,4,5,6,7,8};
	vector<int> p = {1,5,8,9,10,17,17,20};
	vector<vector<int>> t(n+1, vector<int> (n+1, 0));
	cout<<solve(l, p, n, t)<<"\n";

	return 0;
}