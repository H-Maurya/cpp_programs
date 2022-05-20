#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>& s, int temp){
	if(s.empty() || s.top()<=temp){
		s.push(temp);
		return;
	}
	else{
		int val = s.top();
		s.pop();
		insert(s, temp);
		s.push(val);
	}

}

void sort(stack<int>& s){
	if(s.size()<=1){
		return;
	}
	else{
		int val = s.top();
		s.pop();
		sort(s);
		insert(s,val);
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
	sort(s);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}

/*

Initial Stack:				Final Stack:

  | 4 |							| 9 |
  |	3 |							| 6 |
  |	6 |							| 5 |
  |	2 |							| 4 |
  |	9 |							| 3 |
  | 0 |							| 2 |
  | 5 |							| 0 |
  `````							`````

  */