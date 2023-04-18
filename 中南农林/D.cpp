#include<bits/stdc++.h>
using namespace std;
bool f[105][105],usd[105][105];
int mo[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int ans=0,tot=0;
void dfs(int x,int y)
{
	++tot; 
	ans=max(ans,tot);
	usd[x][y]=true;
	for(int i=0;i<4;++i)
		if(!usd[x+mo[i][0]][y+mo[i][1]]&&f[x+mo[i][0]][y+mo[i][1]]) 
			dfs(x+mo[i][0],y+mo[i][1]);
}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		f[x][y]=true;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!usd[i][j]&&f[i][j])
			{
				tot=0;
				dfs(i,j);
			}
	printf("%d",ans);
	return 0;
}
