#include<bits/stdc++.h>
using namespace std;
const long long inf=2147483647;
long long a[2005],dp[2005][25],sum[2005];
long long calc(long long x){
	int now=x%10;
	if(now<5)return x-now;
	return x+10-now;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i){
		dp[i][1]=calc(sum[i]);
		for(int j=2;j<=m+1;++j){
			dp[i][j]=inf;
			for(int k=0;k<i;++k)dp[i][j]=min(dp[i][j],dp[k][j-1]+calc(sum[i]-sum[k]));
		}
	}
	long long ans=inf;
	for(int i=1;i<=m+1;++i)ans=min(ans,dp[n][i]);
	cout<<ans;
	return 0;
}
