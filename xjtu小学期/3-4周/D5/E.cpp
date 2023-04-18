#include<bits/stdc++.h>
using namespace std;
int dp[505][505]; 
int a[505];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dp[i][j]=100000000;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&dp[i][i]);
		a[i]=a[i-1]+dp[i][i];
	}
	for(int len=2;len<=n;++len)
		for(int i=1;i<=n;++i)
		{
			int j=i+len-1;
			for(int k=i+1;k<=j;++k)
				dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[i]*(k-i)+(a[j]-a[k])*(k-i+1));
			dp[i][j]=dp[i+1][j]+a[i]-a[i-1]; 
		}
	printf("%d",dp[1][n]);
	return 0;
}
