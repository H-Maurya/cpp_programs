//Print shortest common supersequence.

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

string print(string x, string y, int m, int n, vector<vector<int>> &t){
	int i=m, j=n;
	string ans ="";
	while(i>0 && j>0) {
		if(x[i-1]==y[j-1]){
			ans+=x[i-1];
			i--; j--;
		}
		else{
			if(t[i-1][j]>t[i][j-1]){
				ans+=x[i-1];
				i--;
			}
			else{
				ans+=y[j-1];
				j--;
			}
		}
	}
	while(i>0){
		ans+=x[i-1];
		i--;
	}
	while(j>0){
		ans+=y[j-1];
		j--;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	string x = "acbcf";
	string y = "abcdaf";
	int m = x.length();
	int n = y.length();
	vector<vector<int>> t(m+1, vector<int> (n+1, 0));
	solve(x,y,m,n,t);
	cout<<print(x,y,m,n,t)<<"\n";
	return 0;
}