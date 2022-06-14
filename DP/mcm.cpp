// Matrix Chain Multiplication Recursive
// Format:
// solve(int arr[], int i, int j){
// 	if(i>=j){
// 		return 0;	//Base Condition
// 	}
// 	for(int k=i; k<=j; k++){
// 		temp = solve(arr, i, k) + solve(arr, k+1, j);		//temp answer
// 		ans = fn(ans,temp)
// 	}
// 	return ans;
// }


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int i, int j){
	int ans = INT_MAX;
	if(i>=j){
		return 0;
	}
	for(int k=i; k<j; k++){
		int temp = solve(v, i, k) + (v[i-1]*v[k]*v[j]) + solve(v, k+1, j);
		ans = min(ans, temp);
	}
	return ans;
}

int main(){
	int ans=0;
	vector<int> v = {40,20,30,10,30};
	cout<<solve(v, 1, v.size()-1)<<"\n";
	return 0;
}