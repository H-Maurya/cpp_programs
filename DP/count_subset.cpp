//Number of subsets with given sum

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int n, int sum, vector<vector<int>> &t){
	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(v[i-1] <= j){
				t[i][j] = (t[i-1][j-v[i-1]] + t[i-1][j]);
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][sum];
}

int main(){
	int n = 6;
	int sum = 10;
	vector<int> v = {2, 3, 5, 6, 8, 10};
	vector<vector<int>> t(n+1, vector<int> (sum+1, 0));
	for(int i=0; i<n+1; i++){
			t[i][0] = 1;
	}
	cout<<solve(v, n, sum, t)<<"\n";
	return 0;
}
