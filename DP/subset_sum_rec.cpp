#include <bits/stdc++.h>
using namespace std;

bool ans = false;

void solve(vector<int> v, int n, int sum){
	if(n==0){
		return;
	}
	if(sum==0){
		ans = true;
		return;
	}
	if(v[n-1]<=sum){
		solve(v, n-1, sum-v[n-1]);
		solve(v, n-1, sum);
		return;
	}
	else{
		solve(v, n-1, sum);
		return;
	}
}

int main(){
	int n = 4;
	int sum = 11;
	vector<int> v = {2, 5, 7, 8};
	solve(v, n, sum);
	cout<<ans<<"\n";
	return 0;
}