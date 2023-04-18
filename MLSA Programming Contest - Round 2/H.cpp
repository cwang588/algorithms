#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long mod=998244353;
long long cnt[1000006],mi[1000006]; 
int n;
int a[200005];
long long calc(int i){
	return ((mi[cnt[i]]-1)*mi[n-cnt[i]]%mod)*i%mod;
}
signed main(){
//	ios::sync_with_stdio(false);
	cin>>n;
	mi[0]=1;
	for(int i=1;i<=n;++i)mi[i]=mi[i-1]*2%mod; 
	for(int i=1;i<=n;++i){
		int t;
		cin>>t;
		a[i]=t;
		++cnt[t];
	}
	long long ans=0;
	for(int i=1;i<=1000000;++i){
		if(!cnt[i])continue;
		ans+=calc(i);
		ans%=mod;
	}
//	cout<<ans<<"\n";
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		int tmp1=a[x],tmp2=y;
		ans-=calc(tmp1)+calc(tmp2);
		ans%=mod;
		--cnt[a[x]];
		++cnt[y];
		a[x]=y;
		ans+=calc(tmp1)+calc(tmp2);
		ans%=mod;
		cout<<(ans+mod)%mod<<"\n";
	}
	return 0;
}
