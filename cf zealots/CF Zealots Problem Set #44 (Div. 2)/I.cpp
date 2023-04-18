#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int a[1005];
long long fac[1004],inv[1005];
int qpow(int a,int b,int p){
	int re=1,now=a;
	while(b){
		if(b&1)re=1ll*re*now%p;
		now=1ll*now*now%p;
		b>>=1;
	}
	return re;
}
void init(){
	fac[0]=1;
	for(int i=1;i<=1000;++i)fac[i]=1ll*fac[i-1]*i%mod;
	inv[1000]=qpow(fac[1000],mod-2,mod);
	for(int i=1000;i>=1;--i)inv[i-1]=inv[i]*i%mod;
}
int C(int x,int y){
	int re=fac[x];
	re=1ll*re*inv[y]%mod;
	re=1ll*re*inv[x-y]%mod;
	return re;
}
int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		int k,n;
		cin>>n>>k;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i){
			int now;
			cin>>now;
			++a[now];
		}
		for(int i=n;i>=1;--i){
			if(k<=a[i]){
				cout<<C(a[i],k)<<"\n";
				break;
			}
			k-=a[i];
		}
	}
	
	
	return 0;
}