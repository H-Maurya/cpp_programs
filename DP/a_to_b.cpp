//Minimum insertion and deletion to convert string a to b

#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int m, int n, vector<vector<int>> &t){
	for(int i=1; i<m+1; i++){
		for(int j=1; j<n+1; j++){
			if(a[i-1]==b[j-1]){
				t[i][j] = 1+t[i-1][j-1];
			}
			else{
				t[i][j] = max(t[i-1][j], t[i][j-1]);
			}
		}
	}
	return t[m][n];
}

using namespace std;
int main(){
	string a = "heap";
	string b = "pea";
	int m = a.length();
	int n = b.length();
	vector<vector<int>> t(m+1, vector<int> (n+1, 0));
	int len = lcs(a,b,m,n,t);
	int del = m-len;
	int ins = n-len;
	cout<<"Deletions: "<<del<<"\nInsertions: "<<ins<<"\n";
	return 0;
}