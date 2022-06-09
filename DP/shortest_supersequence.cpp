// Length of shortest supersequence of two strings

#include <bits/stdc++.h>
using namespace std;

int solve(string x, string y, int m, int n, vector<vector<int>> &t){
	for(int i=1; i<m+1; i++){
		for(int j=1; j<n+1; j++){
			if(x[i-1]==y[j-1]){
				t[i][j] = t[i-1][j-1]+1;
			}
			else{
				t[i][j] = max(t[i-1][j], t[i][j-1]);
			}
		}
	}
	return t[m][n];
}

int main(){
	string x = "aggtab";
	string y = "gxtxayb";
	int m = x.length();
	int n = y.length();
	vector<vector<int>> t(m+1, vector<int> (n+1, 0));
	int length = solve(x,y,m,n,t);
	cout<<m+n-length<<"\n";
	return 0;
}