#include <bits/stdc++.h>
using namespace std;


// METHOD 1

// void solve(string op, int ones, int zeroes){
// 	if(ones==0 && zeroes==0){
// 		cout<<op<<"\n";
// 		return;
// 	}
// 	else{
// 		if(ones==0){
// 			op+='0';
// 			solve(op, ones, zeroes-1);
// 			return;
// 		}
// 		if(ones==zeroes && op.length()==0){
// 			op+='1';
// 			solve(op, ones-1, zeroes);
// 			return;
// 		}
// 		if(ones<=zeroes){
// 			string op1 = op+'1';
// 			string op2 = op+'0';
// 			solve(op1, ones-1, zeroes);
// 			solve(op2, ones, zeroes-1);
// 			return;
// 		} else{
// 			op+='1';
// 			solve(op, ones-1, zeroes);
// 			return;
// 		}
// 	}
// }

// int main(){
// 	int n = 1;
// 	string op = "";
// 	if(n>1){
// 		int ones = ((n+1)/2);
// 		for(int i=ones; i<=n; i++){
// 			solve(op, i, n-i); 
// 		}
// 	} 
// 	else{
// 		solve(op, 1, 0);
// 	}
// 	return 0;
// }




// METHOD 2

void solve(string op, int n, int one, int zero){
	if(n==0){
		cout<<op<<"\n";
		return;
	}
	if(one==zero){
		op+='1';
		solve(op, n-1, one+1, zero);
		return;
	}
	if(one>zero){
		string op1 = op+'1';
		string op2 = op+'0';
		solve(op1, n-1, one+1, zero);
		solve(op2, n-1, one, zero+1);
		return;
	}
}



int main(){
	int n = 6;
	int one = 0;
	int zero = 0;
	string op = "";
	solve(op, n, one, zero);
	return 0;
}