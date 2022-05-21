#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>& s, int val){
	if(s.size()==0){
		s.push(val);
		return;
	}
	else{
		int k = s.top();
		s.pop();
		insert(s,val);
		s.push(k);
		return;
	}
}

void reverse(stack<int>& s){
	if(s.size()==1){
		return;
	}
	else{
		int val = s.top();
		s.pop();
		reverse(s);
		insert(s, val);
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
	reverse(s);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}


/*

Initial Stack:				Final Stack:

  | 4 |							| 5 |
  |	3 |							| 0 |
  |	6 |							| 9 |
  |	2 |							| 2 |
  |	9 |							| 6 |
  | 0 |							| 3 |
  | 5 |							| 4 |
  `````							`````

  */