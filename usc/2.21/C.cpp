#include<bits/stdc++.h>
using namespace std;
int dp[2005][25],a[2005],sum[2005];
int calc(int x){
	int t=x%10;
	if(t<5)return x-t;
	return x-t+10;
}
int main(){
	int n,m;
	cin>>n>>m;
	++m;
	for(int i=1;i<=n;++i)cin>>a[i],sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i){
		dp[i][1]=calc(sum[i]);
		for(int j=2;j<=m;++j){
			dp[i][j]=1e9;
			for(int k=1;k<i;++k)dp[i][j]=min(dp[i][j],dp[k][j-1]+calc(sum[i]-sum[k]));
		}
	}
	int ans=1e9;
	for(int i=1;i<=m;++i)ans=min(ans,dp[n][i]);
	cout<<ans<<"\n";
	return 0;
}