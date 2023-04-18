#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[305],dp[2][305*305*2];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	int base=300*300;
	dp[0][a[2]+base]=1;
	for(int i=2;i<n;++i){
		for(int j=0;j<=base*2;++j)dp[1-(i&1)][j]=0;
		for(int j=0;j<=base*2;++j){
			int now=j-base;
			dp[1-(i&1)][a[i+1]+now+base]+=dp[i&1][j];
			dp[1-(i&1)][a[i+1]+now+base]%=mod;
			if(now){
				dp[1-(i&1)][a[i+1]-now+base]+=dp[i&1][j];
				dp[1-(i&1)][a[i+1]-now+base]%=mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=base*2;++i)ans=(ans+dp[n&1][i])%mod;
	cout<<ans<<"\n";
	return 0;
}