//Check if a subset exist for given sum top-down


#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> v, int n, int sum, vector<vector<bool>> &t){
	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(v[i-1]<=j){
				t[i][j] = (t[i-1][j-v[i-1]] || t[i-1][j]);
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][sum];
}

int main(){
	int n = 5;
	int sum = 11;
	vector<vector<bool>> t(n+1, vector<bool> (sum+1, false));
	for(int i=0; i<n+1; i++){
		t[i][0] = true;
	}
	vector<int> v = {2, 3, 5, 8, 4};
	cout<<solve(v, n, sum, t)<<"\n";
	return 0;
}