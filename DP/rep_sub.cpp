//Longest Repeating Subsequence

#include <bits/stdc++.h>
using namespace std;

int solve(string x, string y, int n, vector<vector<int>> &t){
	for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++){
			if(x[i-1]==y[j-1]){
				if(i!=j){
					t[i][j] = 1+t[i-1][j-1];
				}
				else{
					t[i][j] = max(t[i-1][j],t[i][j-1]);
				}
			}
			else{
				t[i][j] = max(t[i-1][j],t[i][j-1]);
			}
		}
	}
	return t[n][n];
}

int main(){
	string x = "aabebcdd";
	string y = x;
	int n = x.length();
	vector<vector<int>> t(n+1, vector<int> (n+1, 0));
	cout<<solve(x,y,n,t)<<"\n";
	return 0;
}