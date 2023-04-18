#include<bits/stdc++.h>
using namespace std;
int prime[2000005],cnt;
bool notprime[2000005];
void init(){
	for(int i=2;i<=2000000;++i){
		if(!notprime[i])prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=2000000;++j){
			notprime[i*prime[j]]=true;
			if(i%prime[j]==0)break;
		}
	}
}
bool check(int x,string s){
	string num=to_string(x);
	for(int i=0;i+s.length()-1<num.length();++i){
		if(s==num.substr(i,s.length()))return true;
	}
	return false;
}
int main(){
	init();
	int l,r,ans=0;
	string s;
	cin>>l>>r>>s;
	for(int i=l;i<=r;++i){
		if(check(prime[i],s))++ans;
	}
	cout<<ans<<"\n";
	return 0;
}