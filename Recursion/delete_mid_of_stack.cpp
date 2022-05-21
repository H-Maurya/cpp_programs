#include <bits/stdc++.h>
using namespace std;
	
void del(stack<int>& s, int k){
	if(k==1){
		s.pop();
		return;
	}
	else{
		int val = s.top();
		s.pop();
		del(s,k-1);
		s.push(val);
		return;
	}
}

int main(){
	stack<int> s;
	s.push(5);
	s.push(0);
	s.push(9);
	s.push(2);
	s.push(6);
	s.push(3);
	s.push(4);
	int k=ceil(s.size()/2.0);
	del(s,k);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}