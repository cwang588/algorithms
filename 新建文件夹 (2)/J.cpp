#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
double dp[10005][150],fz[10005][150];
int sum[10005];
int main()
{
	int m,n;
	while(cin>>m)
	{
		memset(dp,0,sizeof(dp));
		memset(fz,0,sizeof(fz));
		int tot=m*(m-1)*(m-2)/6;
		for(int i=1;i<=tot;++i)
			for(int j=1;j<=tot;++j)
				scanf("%lf",&fz[i][j]);
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&sum[i]);
			++sum[i];	
		}
		for(int i=1;i<=tot;++i)
			dp[0][i]=1.0;
		for(int i=0;i<n;++i)
			for(int j=1;j<=tot;++j)
			{
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]*fz[j][sum[i+1]]);
				dp[i+1][sum[i+1]]=max(dp[i+1][sum[i+1]],dp[i][j]*fz[j][sum[i+1]]);
			}
		double ans=0.0;
		for(int i=1;i<=tot;++i)
			ans=max(ans,dp[n][i]);
		printf("%.6lf\n",ans);
	}


	return 0;
}
