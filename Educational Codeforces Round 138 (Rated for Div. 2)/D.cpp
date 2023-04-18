#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long qpow(long long a,long long b){
	long long re=1,now=a%mod;
	while(b){
		if(b&1)re=re*now%mod;
		now=now*now%mod;
		b>>=1;
	}
	return re;
}
bool usd[300005];
int prime[300005],cnt;
void init(){
	usd[1]=true;
	for(int i=2;i<=300000;++i){
		if(!usd[i])prime[++cnt]=i;
		for(int j=1;j<=cnt&&prime[j]*i<=300000;++j){
			usd[prime[j]*i]=true;
			if(i%prime[j]==0)break;
		}
	}
}
int main(){
	init();
	int n;
	long long m;
	cin>>n>>m;
	long long ans=0,tot=1,now=1;
	for(int i=1;i<=n;++i){
		if(!usd[i]&&now<=m)now*=i;
		tot=tot*((m/now)%mod)%mod;
		ans+=(qpow(m,i)-tot)%mod;
		ans=(ans%mod+mod)%mod;
	}
	cout<<ans%mod<<"\n";
	return 0;
}