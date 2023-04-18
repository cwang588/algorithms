#include<bits/stdc++.h>
using namespace std;
int a[100005];
long long sum[100005],dp[100005][455];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],sum[i]=sum[i-1]+a[i];
		int m=sqrt(2*n),ans=1;
		for(int i=1;i<=n+1;++i){
			for(int j=1;j<=450;++j)dp[i][j]=0;
		}
		for(int i=n;i>=1;--i){
			dp[i][1]=max(dp[i+1][1],1ll*a[i]);
			for(int j=2;j<=min(m,n-i);++j){
				dp[i][j]=dp[i+1][j];
				if(dp[i+j][j-1]>sum[i+j-1]-sum[i-1])dp[i][j]=max(dp[i][j],sum[i+j-1]-sum[i-1]);
				if(dp[i][j])ans=max(ans,j);
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}