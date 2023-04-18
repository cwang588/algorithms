#include<bits/stdc++.h>
using namespace std;
int a[305],dp[308][308];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dp[i][j]=1;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int len=2;len<=n;++len)
		for(int i=1;i<n;++i)
		{
			int j=i+len-1;
			for(int k=i;k<=j;++k)
				dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[k]*(len-1)); 
		}
	printf("%d",dp[1][n]);
	return 0;
}
