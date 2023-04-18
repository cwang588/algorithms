#include<bits/stdc++.h>
using namespace std;
int n;
long long a[505],sum[505];
long long dp[505][505];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		dp[i][i]=1;
	}
	a[0]=a[n+1]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i-1][i-1]*=a[i];
		dp[i+1][i+1]*=a[i];
	}
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			for(int k=i;k<=j;k++)
				dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[i-1]*a[j+1]);
		}
	}
	printf("%lld",dp[1][n]);
	return 0;
} 

