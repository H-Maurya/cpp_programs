//Longest Common Subsequence Recursive

#include <bits/stdc++.h>
using namespace std;

int solve(string x, string y){
	int m = x.length();
	int n = y.length();
	if(m==0 || n==0){
		return 0;
	}
	else{
		if(x[m-1]==y[n-1]){
			return 1+solve(x.substr(0,m-1), y.substr(0, n-1));
		}
		else{
			return max(solve(x.substr(0,m-1), y.substr(0, n)), solve(x.substr(0,m), y.substr(0, n-1)));
		}
	}
}

int main(){
	string x = "billionare";
	string y = "millionare";
	int n = x.length();
	int m = y.length();
	cout<<solve(x,y)<<"\n";
	return 0;
}


//Longest Common Subsequence Memoisation

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t(1001, vector<int> (1001, -1));

int solve(string x, string y, int n, int m){
	if(m==0 || n==0){
		return 0;
	}
	if(t[n][m]!=-1){
		return t[n][m];
	}
	if(x[m-1]==y[n-1]){
		return t[n][m] = 1+solve(x, y, m-1, n-1);
	}
	else{
		return t[n][m] = max(solve(x, y, m-1, n), solve(x, y, m, n-1));
	}
}

int main(){
	string x = "abcf";
	string y = "abcdaf";
	int n = x.length();
	int m = y.length();
	cout<<solve(x,y,n,m)<<"\n";
	return 0;
}


//Longest Common Subsequence Top-Down

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t(1001, vector<int> (1001, 0));

int solve(string x, string y, int n, int m){
	for(int i=1; i<n+1; i++){
		for(int j=1; j<m+1; j++){
			if(x[i-1]==y[j-1]){
				t[i][j] = 1+t[i-1][j-1];
			}
			else{
				t[i][j] = max(t[i-1][j], t[i][j-1]); 
			}
		}
	}
	return t[n][m];
}

int main(){
	string x = "billionare";
	string y = "millionare";
	int n = x.length();
	int m = y.length();
	cout<<solve(x,y,n,m)<<"\n";
	return 0;
}