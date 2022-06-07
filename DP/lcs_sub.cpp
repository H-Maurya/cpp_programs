//Longest Common Substring

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t(1001, vector<int> (1001, 0));

int solve(string x, string y, int n, int m){
	int result = 0;
	for(int i=1; i<n+1; i++){
		for(int j=1; j<m+1; j++){
			if(x[i-1]==y[j-1]){
				t[i][j] = 1+t[i-1][j-1];
				result = max(t[i][j], result);
			}
			else{
				t[i][j] = 0; 
			}
		}
	}
	return result;
}

int main(){
	string x = "billioare";
	string y = "millionare";
	int n = x.length();
	int m = y.length();
	cout<<solve(x,y,n,m)<<"\n";
	return 0;
}