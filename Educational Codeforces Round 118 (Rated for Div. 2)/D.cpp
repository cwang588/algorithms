#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int a[500005],dp[5000005][2];
signed main(){
	int t;
	cin>>t;	
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],dp[i][0]=dp[i][1]=0;
		dp[0][0]=dp[0][1]=0;
		for(int i=1;i<=n;++i){
			if(a[i]==0){
				dp[0][0]=(dp[0][0]*2+1)%mod;
				dp[2][1]=dp[2][1]*2%mod;
			}
			else if(a[i]==1){
				dp[1][1]=(dp[1][1]*2+1)%mod;
				dp[1][0]=(dp[1][0]*2+dp[0][0])%mod;
				dp[3][1]=dp[3][1]*2%mod;
			}
			else{
				dp[a[i]][0]=(dp[a[i]][0]*2%mod+dp[a[i]-1][0])%mod;
				dp[a[i]][1]=(dp[a[i]][1]*2%mod+dp[a[i]-2][0])%mod;
				dp[a[i]+2][1]=dp[a[i]+2][1]*2%mod;
			}
		}
		int ans=0;
		for(int i=0;i<=n;++i)ans=(ans+dp[i][0]+dp[i][1])%mod;
		cout<<ans<<"\n";
	}
	return 0;
}