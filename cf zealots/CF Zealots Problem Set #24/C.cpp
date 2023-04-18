#include<bits/stdc++.h>
using namespace std;
long long dp[100005][34];
int a[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i){
			dp[i][0]=dp[i-1][0]+a[i]-k;
			int now=a[i];
			for(int j=1;j<=32;++j){
				now>>=1;
			 	dp[i][j]=max(dp[i-1][j-1]+now,dp[i-1][j]+now/2-k);
			}
			dp[i][32]=max(dp[i-1][32],dp[i][32]);
		}
		long long ans=0;
		for(int i=0;i<=32;++i)ans=max(ans,dp[n][i]);
		cout<<ans<<"\n";
	}
	
	
	return 0;
}