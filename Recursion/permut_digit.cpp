//All permutation of string with case change and digit

#include <bits/stdc++.h>
using namespace std;

vector<string> v;

bool isDigit(char c){
	if(c>='0' && c<='9') {
		return true;
	}
	return false;
}

char change_case (char c) {
    if (isupper(c)) 
        return tolower(c); 
    else
        return toupper(c); 
}

void solve(string ip, string op){
	if(ip.length()==0){
		v.push_back(op);
		return;
	}
	else{
		if(isDigit(ip[0])){
			string op1 = op;
			while(isDigit(ip[0])){
				op1.push_back(ip[0]);
				ip.erase(ip.begin()+0);
			}
			solve(ip, op1);
			return;
		}
		else{
			string op1 = op+ip[0];
			string op2 = op+change_case(ip[0]);
			ip.erase(ip.begin()+0);
			solve(ip, op1);
			solve(ip, op2);
			return;
		}
		
	}

}
int main(){
	string ip = "a1B2";
	string op = "";
	solve(ip, op);
	for(auto it:v){
		cout<<it<<"\n";
	}
	return 0;
}