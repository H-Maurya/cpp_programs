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
	int n = 4;
	vector<int> v = {1, 6, 7, 5};
	vector<int> range;
	int sum = 0;
	for(auto it:v){
		sum+=it;
	}
	vector<vector<bool>> t(n+1, vector<bool> (sum+1, false));
	for(int i=0; i<n+1; i++){
		t[i][0] = true;
	}
	solve(v, n, sum, t);
	for(int i=0; i<=sum; i++){
		if(t[n][i]){
			range.push_back(i);
		}
	}	
	cout<<sum-(2*range[(range.size()/2)-1])<<"\n";	
	return 0;
}