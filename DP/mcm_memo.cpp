//Matrix Chain Multiplication Memoisation


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int i, int j, vector<vector<int>> &t){
	int ans = INT_MAX;
	if(i>=j){
		return 0;
	}
	if(t[i][j]!=-1){
		return t[i][j];
	}
	for(int k=i; k<j; k++){
		int temp = solve(v, i, k, t) + (v[i-1]*v[k]*v[j]) + solve(v, k+1, j, t);
		ans = min(ans, temp);
	}
	return t[i][j] = ans;
}

int main(){
	int ans=0;
	vector<int> v = {40,20,30,10,30};
	vector<vector<int>> t(1001, vector<int> (1001, -1));
	cout<<solve(v, 1, v.size()-1, t)<<"\n";
	return 0;
}