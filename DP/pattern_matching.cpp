//Check if string "a" is a subsequence of "b";

#include <bits/stdc++.h>
using namespace std;

int solve(string x, string y, int m, int n, vector<vector<int>> &t) {
	for(int i=1; i<m+1; i++){
		for(int j=1; j<n+1; j++){
			if(x[i-1]==y[j-1]){
				t[i][j] = 1+t[i-1][j-1];
			}
			else{
				t[i][j] = max(t[i][j-1], t[i-1][j]);
			}
		}
	}
	return t[m][n];
}

int main(){
	string x = "axy";
	string y = "adxcpy";
	int m = x.length();
	int n = y.length();
	vector<vector<int>> t(m+1, vector<int> (n+1, 0));
	if(solve(x,y,m,n,t)==x.length()){
		cout<<true<<"\n";
	}
	else{
		cout<<false<<"\n";
	}


	return 0;
}