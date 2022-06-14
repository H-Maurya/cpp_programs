//Minimum insertions to make string a palindrome

#include <bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int n, vector<vector<int>> &t){
	for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++){
			if(x[i-1]==y[j-1]) {
				t[i][j] = 1+t[i-1][j-1];
			}
			else{
				t[i][j] = max(t[i-1][j], t[i][j-1]);
			}
		}
	}
	return t[n][n];
}

int main(){
	string x = "acbcbda";
	string y = x;
	int n = x.length();
	reverse(y.begin(), y.end());
	vector<vector<int>> t(n+1, vector<int> (n+1, 0));
	int len = lcs(x,y,n,t);
	cout<<(n-len)<<"\n";
	return 0;
}