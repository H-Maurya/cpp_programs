#include <bits/stdc++.h>
using namespace std;

vector<string> generate(int open, int close, string op, vector<string>& ans){
	if(open==0 && close==0){
		ans.push_back(op);
		return ans;
	}
	if(op.length()==0){
		op+='(';
		generate(open-1, close, op, ans);
		return ans;
	}
	else{
		if(open>close){
			return ans;
		}
		else{
			if(open!=0){
				string op1=op+'(';
				string op2=op+')';
				generate(open-1, close, op1, ans);
				generate(open, close-1, op2, ans);
				return ans;
			}
			else{
				op+=')';
				generate(open, close-1, op, ans);
				return ans;
			}
		}
	}
}

int main(){
	int n=4;
	int open = n;
	int close = n;
	string op = "";
	vector<string> ans;
	generate(open, close, op, ans);
	for(auto it: ans){
		cout<<it<<"\n";
	}

	return 0;
}