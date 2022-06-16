//Palindrome partitioning recusive
//Minimum partitions to make substring palindrome

#include<bits/stdc++.h>
using namespace std;

bool isPal(string s, int i, int j){
	while(i < j)
    {
      if(s[i] != s[j])
        return false; 
      i++;
      j--;
    }
    return true;
}

solve(string s, int i, int j){
	int ans = INT_MAX;
	if(i>=j){
		return 0;
	}
	if(isPal(s,i,j)){
		return 0;
	}
	for(int k=i; k<j; k++){
		int temp = solve(s, i, k) + 1 + solve(s, k+1, j);
		ans = min(ans, temp);
	}
	return ans;
}

int main(){
	string s = "nitin";
	cout<<solve(s,0,s.length()-1)<<"\n";
	return 0;
}