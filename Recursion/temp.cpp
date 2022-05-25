#include <bits/stdc++.h>
using namespace std;

bool possible = false;

void solve(vector<int>& v, int a, int b, int turn){
	if(possible) return;
	if(v.size()==0){
		possible = (a>=b) ? true : false ;
	}
	else{
		if(turn==1){
			vector<int> v1 = v;
			vector<int> v2 = v;
			int a1 = a+v1[0];
			int a2 = a+v2[v2.size()-1];
			v1.erase(v1.begin()+0);
			v2.erase(v2.end()-1);
			solve(v1, a1, b, 2);
			solve(v2, a2, b, 2);

		}
		else{
			vector<int> v1 = v;
			vector<int> v2 = v;
			int b1 = b+v1[0];
			int b2 = b+v2[v2.size()-1];
			v1.erase(v1.begin()+0);
			v2.erase(v2.end()-1);
			solve(v1, a, b1, 1);
			solve(v2, a, b2, 1);
		}
	}
}

int main(){
	vector<int> v = {1,5,2};
	int a = 0, b = 0, turn = 1;
	solve(v, a, b, turn);
	cout<<possible<<"\n";
	return 0;
}