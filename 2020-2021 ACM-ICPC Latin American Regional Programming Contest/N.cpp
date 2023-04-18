#include<bits/stdc++.h>
using namespace std;
void work(string s,int &now){
	int x=0;
	bool ky=false;
	for(int i=0;i<s.length();++i){
		if(ky)x=x*10+s[i]-'0';
		if(s[i]=='.')ky=true;
	}
	now+=x;
}
int main(){
	int n;
	string s;
	int now=0;
	cin>>n>>s;
	work(s,now);
	int ans=0;
	for(int i=1;i<=n;++i){
		cin>>s;
		work(s,now);
		if(now%100)++ans;
	}
	cout<<ans<<endl; 
	return 0;
}
