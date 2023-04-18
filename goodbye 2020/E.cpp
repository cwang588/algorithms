#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int cnt[500005][65];
long long a[500005],mi[65];
void init(){
	mi[0]=1;
	for(int i=1;i<=60;++i)mi[i]=mi[i-1]*2;
}
void work(int tmp,long long now){
	for(int i=60;i>=0;--i){
		if(now>=mi[i]){
			++cnt[tmp][i];
			now-=mi[i];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		init();
		int n;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			for(int j=0;j<=60;++j)cnt[i][j]=cnt[i-1][j];
			work(i,a[i]);
			a[i]%=mod;
		}
		for(int i=1;i<=60;++i)mi[i]%=mod;
		long long ans=0;
		for(int i=1;i<=n;++i){
			long long ans1=0,ans2=0;
			for(int j=0;j<=60;++j){
				ans1=(ans1+(cnt[i][j]-cnt[i-1][j])*cnt[n][j]*mi[j])%mod;
				if(cnt[i][j]-cnt[i-1][j])ans2=(ans2+n*mi[j])%mod;
				else ans2=(ans2+cnt[n][j]*mi[j])%mod;
			}
			ans=(ans+ans1*ans2)%mod;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
