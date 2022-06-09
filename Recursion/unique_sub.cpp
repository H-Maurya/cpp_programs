//Print unique substring

#include <bits/stdc++.h>
using namespace std;

set<string> ans;

void substring(string ip, string op){
	if(ip.length()==0){
		ans.insert(op);
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
	string ip = "abb";
	string op = "";
	substring(ip, op);
	for (auto itr = ans.begin(); itr != ans.end(); itr++) {
        cout << *itr << "\n";
    }
	return 0;
}