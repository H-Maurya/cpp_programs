//Sort array using recursion

#include <bits/stdc++.h>
using namespace std;

void insert(vector<int>& v, int temp){
	if(v.size()==0 || v[v.size()-1]<=temp){
		v.push_back(temp);
		return;
	}
	else{
		int val = v[v.size()-1];
		v.pop_back();
		insert(v, temp);
		v.push_back(val);
		return;
	}
}

void sort(vector<int>& v){
	if(v.size()<=1){
		return;
	}
	else{
		int val=v[v.size()-1];
		v.pop_back();
		sort(v);
		insert(v,val);
		return;
	}
}

int main(){
	vector<int> v = {1,0,4,2,6};
	sort(v);
	for(int it:v){
		cout<<it<<" ";
	}
	return 0;
}