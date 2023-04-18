#include<bits/stdc++.h>
using namespace std;
const long long INF=21474836477777;
long long a[805],p[805][805],dp[805][805];
int main()
{
	int n,m,kk,y;
	scanf("%d%d%d%d",&n,&m,&kk,&y);
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>p[i][j];
	for(int i=0;i<=n;++i)
		for(int j=1;j<=kk;++j)
			dp[i][j]=INF;
	for(int i=1;i<=m;++i)p[0][i]=INF;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=kk;++j)
			for(int k=1;k<=min(j,m);++k)
			{
				dp[i][j]=min(dp[i-1][j],dp[i][j]);
				if(k>=y)
					dp[i][j]=min(dp[i][j],dp[i-1][j-k]+p[i][k]);
				else 
					dp[i][j]=min(dp[i][j],dp[i-1][j-k]+p[i][k]+k*a[i]);
			}
	printf("%lld\n",dp[n][kk]);
	return 0;
}
