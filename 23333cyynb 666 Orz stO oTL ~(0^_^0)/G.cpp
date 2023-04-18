#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long quickpower(long long a,long long b,long long p){
	long long now=a,re=1;
	while(b){
		if(b&1)re=re*now%p;
		now=now*now%p;
		b>>=1;
	}
	return re;
}
int main(){
	int n;
	cin>>n;
	if(n%2)return !printf("0\n");
	long long ans=1;
	for(int i=1;i<=n;i+=2)ans=ans*i%mod;
	for(int i=1;i<=n/2-2;++i)ans=ans*(n/2)%mod;
	for(int i=1;i<=n/2-1;++i)ans=ans*4%mod;
	cout<<ans<<endl;
	return 0;
}
