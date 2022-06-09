//Check whether subset with equal sum exists or not

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
	vector<int> arr = {1, 11, 5, 5};
	int n = 4;
	int sum = 0;
	for(auto it:arr){
		sum+=it;
	}
	if(sum&1){
		cout<<false<<"\n";
	}
	else{
		sum/=2;
		vector<vector<bool>> t(n+1, vector<bool> (sum+1, false));
		for(int i=0; i<n+1; i++){
			t[0][i] = true;
		}
		cout<<solve(arr, n, sum, t)<<"\n";
	}
	return 0;
}