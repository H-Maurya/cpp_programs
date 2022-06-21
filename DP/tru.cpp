//Evaluate expression to true  aka  Boolean Parenthesisation Recursive

#include <bits/stdc++.h>
using namespace std;


int solve(string s, int i, int j, bool b){
	int ans = 0;
	if(i>j){
		return false;
	}
	if(i==j){
		if(b){
			return s[i]=='T';
		}
		else{
			return s[i]=='F';
		}
	}
	for(int k=i+1; k<j; k+=2){
		bool lt=solve(s,i,k-1,true);
		bool lf=solve(s,i,k-1,false);
		bool rt=solve(s,k+1,j,true);
		bool rf=solve(s,k+1,j,false);
		if(s[k]=='&'){
			if(b==true){
				ans+=(lt*rt);
			}
			else{
				ans+=((lf*rt)+(lf*rf)+(lt*rf));
			}
		}
		else if(s[k]=='|'){
			if(b==true){
				ans+=((lt*rt)+(lt*rf)+(lf*rt));
			}
			else{
				ans+=(lf*rf);
			}
		}
		else{
			if(b==true){
				ans+=((lt*rf)+(lf*rt));
			}
			else{
				ans+=((lt*rt)+(lf*rf));
			}
		}
	}
	return ans;
}

int main(){
	string s = "T|F&T^F";
	int n = s.length();
	cout<<solve(s, 0, n-1, true)<<"\n";
	return 0;
}