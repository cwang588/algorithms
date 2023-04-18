#include<bits/stdc++.h>
using namespace std;
long long a[100005],dp[100005][35];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		long long k;
		cin>>n>>k;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=31;++i)dp[0][i]=-1e18;
		for(int i=1;i<=n;++i){
			dp[i][0]=dp[i-1][0]+a[i]-k;
			for(int j=1;j<=30;++j)dp[i][j]=max(dp[i-1][j]-k,dp[i-1][j-1])+(a[i]>>j);
			dp[i][31]=max(dp[i-1][31],dp[i-1][30]);
		}
		long long ans=-1e18;
		for(int i=0;i<=31;++i)ans=max(ans,dp[n][i]);
		cout<<ans<<"\n";
	}
	
	
	return 0;
}