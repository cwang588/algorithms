#include<bits/stdc++.h>
using namespace std;
int dp[200005][2],a[200005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),dp[i][0]=dp[i][1]=214748364;
		dp[0][0]=21474837;
		dp[0][1]=0;
		for(int i=1;i<=n;++i)
		{
			dp[i][0]=dp[i-1][1]+a[i];
			if(i>=2)dp[i][0]=min(dp[i][0],dp[i-2][1]+a[i]+a[i-1]);
			dp[i][1]=dp[i-1][0];
			if(i>=2)dp[i][1]=min(dp[i][1],dp[i-2][0]);
		}
		printf("%d\n",min(dp[n][0],dp[n][1]));
	}
	return 0;
}
