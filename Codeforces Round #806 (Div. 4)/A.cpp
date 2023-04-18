#include<bits/stdc++.h>
using namespace std;
bool check(string s){
	if(s[0]!='y'&&s[0]!='Y')return false;
	if(s[1]!='e'&&s[1]!='E')return false;
	if(s[2]!='s'&&s[2]!='S')return false;
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		if(check(s))cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	
	
	return 0;
}