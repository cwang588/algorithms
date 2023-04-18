#include<bits/stdc++.h>
using namespace std;
bool check(string s){
	int n=s.length();
	for(int i=0;i<n;++i){
		if(s[i]!=s[n-i-1])return false;
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		if(check(s))cout<<"1\n";
		else{
			if(k==0)cout<<"1\n";
			else cout<<"2\n";
		}
	}
	
	return 0;
}