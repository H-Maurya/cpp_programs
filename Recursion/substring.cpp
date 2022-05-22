#include <bits/stdc++.h>
using namespace std;

void substring(string ip, string op){
	if(ip.length()==0){
		cout<<op<<"\n";
		return;
	}
	else{
		string op1 = op, op2 = op+ip[0];
		ip.erase(ip.begin());
		substring(ip, op1);
		substring(ip, op2);
		return;
	}
}

int main(){
	string ip = "abc";
	string op = "";
	substring(ip, op);
	return 0;
}