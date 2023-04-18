#include<bits/stdc++.h>
using namespace std;
long long a[105];
long long dp[105][10005];
int main()
{
	int n;
	long long t;
	cin>>n;
	while(n)
	{
		memset(dp,0,sizeof(dp));
		cin>>t;
		for(int i=1;i<=t;++i)cin>>a[i];
		for(int i=t;i>=1;--i)
			for(int j=n;j>=1;--j)
			{
				if(j>=a[i])dp[i][j]=max(dp[i+1][j-a[i]]+a[i],dp[i+1][j]);
				else dp[i][j]=dp[i+1][j];
			}
		long long Max=0;
		for(long long i=1;i<=n;++i)Max=max(Max,dp[1][i]);
		int now=Max;
		for(int i=1;i<=t;++i)
		{
			if(a[i]<=now)
			{
				if(a[i]+dp[i+1][now-a[i]]==now)
				{
					printf("%lld ",a[i]);
					now-=a[i];
				}
			}
			if(!now)break;
		}
		printf("%lld\n",Max);
		cin>>n;
	}
	return 0;
}
