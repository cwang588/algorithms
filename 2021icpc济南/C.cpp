#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod=998244353;
long long fac[1000006];
int a[1000006], cnt[1000006];
bool isodd[1000006];
long long quickpower(long long a,long long b,long long p){
	long long re=1,now=a;
	while(b){
		if(b&1)re=re*now%p;
		now=now*now%p;
		b>>=1;
	}
	return re;
}
long long C(int x,int y){
	long long re=fac[x];
	re=re*quickpower(fac[y],mod-2,mod)%mod;
	re=re*quickpower(fac[x-y],mod-2,mod)%mod;
	return re;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		cnt[a[i]]++;
	}
	fac[0]=1;
	int spaces = 1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] & 1) {
			isodd[i] = true;
		}
	}
	ll ret = 1;
	for (int i = 1; i <= n; ++i) {
		ret = ret * fac[cnt[i]] % mod;
		if (isodd[i]) spaces++;
		if (cnt[i] <= 1) continue;
		if (isodd[i]) spaces--;
		ret = ret * C(spaces+cnt[i]/2-1,spaces-1) % mod;
		if (isodd[i]) spaces++;
		spaces += cnt[i] / 2 * 2;
	}
	cout << ret << '\n';
	return 0;
}