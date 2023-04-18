#include<bits/stdc++.h>
using namespace std;
int prime[100005],cnt;
bool usd[100005];
void init(){
	usd[1]=true;
	for(int i=1;i<=100000;++i){
		if(!usd[i])prime[++cnt]=i;
		for(int j=1;j<=cnt&&1ll*i*prime[j]<=100000;++j){
			usd[i*prime[j]]=true;
			if(i%prime[j]==0)break;	
		}
	}
}
int main(){
	int t;
	cin>>t;
	init();
	while(t--){
		long long n;
		cin>>n;
		set<int>s;
		long long tmp=n;
		for(int i=1;1ll*prime[i]*prime[i]<=tmp;++i){
			if(tmp%prime[i]==0){
				s.insert(prime[i]);
				while(tmp%prime[i]==0)tmp/=prime[i];
			}
		}
		if(tmp>1)s.insert(tmp);
		tmp=n+1;
		for(int i=1;1ll*prime[i]*prime[i]<=tmp;++i){
			if(tmp%prime[i]==0){
				s.insert(prime[i]);
				while(tmp%prime[i]==0)tmp/=prime[i];
			}
		}
		if(tmp>1)s.insert(tmp);
		cout<<s.size()<<endl;
	}
	
	return 0;
}
