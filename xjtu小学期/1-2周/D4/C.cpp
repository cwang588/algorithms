#include<bits/stdc++.h>
using namespace std;
int n,m;
int move[8][2]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
long long qp[2005][2005],dp[2005][2005];
bool usd[2005][2005],sou[2005][2005];
long long ans=0;
long long dfs(int x,int y,long long tot)
{
	usd[x][y]=true;
	tot+=qp[x][y];
	for(int i=0;i<8;++i)
	{
		int xx=x+move[i][0],yy=y+move[i][1];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&!usd[xx][yy]&&qp[xx][yy]<qp[x][y])
		{
			if(!sou[xx][yy])
				dp[xx][yy]=dfs(xx,yy,tot);
			dp[x][y]=max(dp[xx][yy]+qp[x][y],dp[x][y]);
		}
	}
	usd[x][y]=false;
	sou[x][y]=true;
	return dp[x][y];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			scanf("%lld",&qp[i][j]);
			dp[i][j]=qp[i][j];
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			dp[i][j]=dfs(i,j,0);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			ans=max(ans,dp[i][j]);
	printf("%lld",ans);
	return 0;
}
