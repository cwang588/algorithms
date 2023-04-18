#include<bits/stdc++.h>
using namespace std;
int n;
int a[505],sum[505];
int dp[505][505];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			dp[i][j]=dp[i+1][j]+sum[j]-sum[i];
			for(int k=i+1;k<=j;k++)
				dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]+a[i]*(k-i)+(sum[j]-sum[k])*(k-i+1));
		}
	}
	printf("%d",dp[1][n]);
	return 0;
} 
