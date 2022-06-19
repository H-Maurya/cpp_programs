//Palindrome partitioning memoisation

#include <bits/stdc++.h>
using namespace std;

bool isPal(string s, int i, int j){
	while(i<j){
		if(s[i]!=s[j]){
			return false;
		}
		i++;j--;
	}
	return true;
}

int solve(string s, int i, int j, vector<vector<int>> &t){
	int ans = INT_MAX;
	if(i>=j){
		return 0;
	}
	if(isPal(s,i,j)){
		return 0;
	}
	if(t[i][j]!=-1){
		return t[i][j];
	}
	for(int k=i; k<j; k++){
		int temp = solve(s,i,k,t)+1+solve(s,k+1,j,t);
		ans = min(ans,temp);
	}
	return t[i][j] = ans;
}

int main(){
	string s = "nitin";
	int n = s.length();
	vector<vector<int>> t(n+1, vector<int> (n+1, -1));
	cout<<solve(s,0,n-1,t)<<"\n";
	return 0;
}


//Optimised

#include <bits/stdc++.h>
using namespace std;

bool isPal(string s, int i, int j){
	while(i<j){
		if(s[i]!=s[j]){
			return false;
		}
		i++;j--;
	}
	return true;
}

int solve(string s, int i, int j, vector<vector<int>> &t){
	int ans = INT_MAX;

	if(i>=j){
		return 0;
	}
	if(isPal(s,i,j)){
		return 0;
	}
	if(t[i][j]!=-1){
		return t[i][j];
	}
	for(int k=i; k<j; k++){
		int left,right;		//function call seperately
		if(t[i][k]!=-1){
			left=t[i][k];
		}
		else{
			left = solve(s,i,k,t);
		}
		if(t[k+1][j]!=-1){
			right=t[k+1][j];
		}
		else{
			right = solve(s,i,k,t);
		}
		ans = min(ans,left+1+right);
	}
	return t[i][j] = ans;
}

int main(){
	string s = "nitin";
	int n = s.length();
	vector<vector<int>> t(n+1, vector<int> (n+1, -1));
	cout<<solve(s,0,n-1,t)<<"\n";
	return 0;
}
