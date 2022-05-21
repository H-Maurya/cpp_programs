#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k){
	if(n==1){
		return 0;
	}
	else{
		int len = pow(2, n-1);
		if(k<=(len/2)){
			return solve(n-1, k);
		}
		else{
			return !solve(n-1, k-(len/2));
		}
	}
}


int main(){
	int n = 2, k = 2;
	cout<<solve(n, k);
	return 0;
}