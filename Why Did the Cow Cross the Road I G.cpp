#include<bits/stdc++.h>
using namespace std;
int n,t;
long long a[105][105];
long long ans=2147483647;
int mov[16][2]={{-3,0},{3,0},{0,3},{0,-3},{2,1},{1,2},{-2,1},{-1,2},{1,-2},{2,-1},{-1,-2},{-2,-1},{0,1},{1,0},{-1,0},{0,-1}};
bool usd[105][105];
void dfs(int x,int y,long long tot)
{
	if(x==n&&y==n)
	{
		ans=min(ans,tot);
		return;
	}
	if(tot>=ans)return;
	if(2*n-x-y<=2)
	{
		dfs(n,n,tot+t*(2*n-x-y));
		return;
	}
	for(int i=1;i<=16;++i)
	{
		int xx=x+mov[i][0],yy=y+mov[i][1]; 
		if(xx<=0||xx>n||yy<=0||yy>n||usd[xx][yy])continue;
		usd[xx][yy]=true;
		dfs(xx,yy,tot+3*t+a[xx][yy]);
		usd[xx][yy]=false;
	}
}
int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%lld",&a[i][j]);
	usd[1][1]=true;
	dfs(1,1,0);
	printf("%lld\n",ans);
	return 0;
}
