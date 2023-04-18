#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200004];
long long dp[200005][3];
int main()
{
	int n;
	long long Max=-99999999;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),Max=max(Max,a[i]);
	for(int i=1;i<=n;++i)scanf("%lld",&b[i]),Max=max(Max,b[i]);
	if(Max<=0)return !printf("%lld",Max);
	for(int i=1;i<=n;++i)
	{
		dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i];
		dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b[i];
		dp[i][2]=max(max(dp[i-1][1],dp[i-1][0]),dp[i-1][2]);
	}
	long long ans=0;
	ans=max(ans,dp[n][0]);
	ans=max(ans,dp[n][1]);
	ans=max(ans,dp[n][2]);
	printf("%lld\n",ans);
	return 0;
} 
