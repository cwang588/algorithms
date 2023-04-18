#include<bits/stdc++.h>
using namespace std;
int cnt[35];
int main(){
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	for(int i=0;i<n;++i){
		if(s[i]!=t[i])++cnt[s[i]-'A'+1];
	}
	for(int i=0;i<n;++i){
		if(s[i]==t[i])cout<<"Y";
		else{
			if(!cnt[t[i]-'A'+1])cout<<"X";
			else cout<<"N";
		}
	}
	return 0;
}