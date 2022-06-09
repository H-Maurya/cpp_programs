//All permutations of string with case change allowed

#include <bits/stdc++.h>
using namespace std;

char change_case (char c) {
    if (isupper(c)) 
        return tolower(c); 
    else
        return toupper(c); 
}

void solve(string ip, string op){
	if(ip.length()==0){
		cout<<op<<"\n";
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


int main(){
	string ip = "ABc";
	string op = "";
	solve(ip, op);

	return 0;
}