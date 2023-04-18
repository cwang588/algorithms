#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
long long jc[200005];
long long quickpower(long long a,long long b,long long p){
	long long re=1,now=a;
	while(b){
		if(b&1)re=re*now%p;
		now=now*now%p;
		b>>=1;
	}
	return re;
}
int main(){
	int t;
	cin>>t;
	jc[0]=1;
	for(int i=1;i<=200000;++i)jc[i]=jc[i-1]*i%mod;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+1+n,cmp);
		if(a[1]==a[2]){
			cout<<jc[n]<<"\n";
			continue;
		}
		if(a[1]>a[2]+1){
			cout<<"0\n";
			continue;
		}
		int cnt=0;
		long long ans=0;
		for(int i=1;i<=n;++i)if(a[i]==a[2])++cnt;
		for(int i=1;i<=n;++i){
			ans=(ans+jc[n-1])%mod;
			if(i-1<cnt)continue;
			ans-=(jc[i-1]*jc[n-1-cnt]%mod)*quickpower(jc[i-1-cnt],mod-2,mod)%mod;
			ans%=mod;
		}
		cout<<(ans+mod)%mod<<"\n";
	}
	return 0;
}
