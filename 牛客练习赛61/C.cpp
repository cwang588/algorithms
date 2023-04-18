#include<bits/stdc++.h>
using namespace std;
int fa[1005],sz[1005];
int getfa(int x)
{
	if(x!=fa[x])fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	fa[x]=y;
	sz[y]+=sz[x];
}
int dp[15][15][15][15][15];
int sum[15],num;
bool usd[15];
int main()
{
	int a,b,c,d,m;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&m);
	for(int i=1;i<=12;++i)fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int r1=getfa(x),r2=getfa(y);
		if(r1!=r2)Merge(r1,r2);
	}
	for(int i=1;i<=12;++i)getfa(i);
	for(int i=1;i<=12;++i)
	{
		if(!usd[fa[i]])
		{
			sum[++num]=sz[fa[i]];
			usd[fa[i]]=true;
		}
	}
	for(int i=0;i<=num;++i)
		dp[i][0][0][0][0]=1;
	for(int i=1;i<=num;++i)
		for(int j=0;j<=12;++j)
			for(int k=0;k<=12;++k)
				for(int x=0;x<=12;++x)
					for(int y=0;y<=12;++y)
					{
						if(j>=sum[i])dp[i][j][k][x][y]+=dp[i-1][j-sum[i]][k][x][y];
						if(k>=sum[i])dp[i][j][k][x][y]+=dp[i-1][j][k-sum[i]][x][y];
						if(x>=sum[i])dp[i][j][k][x][y]+=dp[i-1][j][k][x-sum[i]][y];
						if(y>=sum[i])dp[i][j][k][x][y]+=dp[i-1][j][k][x][y-sum[i]];
					}
	printf("%d\n",dp[num][a][b][c][d]);
	return 0;
}
