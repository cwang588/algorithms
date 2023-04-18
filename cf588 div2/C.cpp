#include<cstdio>
#include<cstring>
using namespace std;
int g[15][15];
int mp[15][15];
int b[15];
int n,m,ln=0,ans;
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x][y]=g[y][x]=true;
	}
}
void dfs(int x)
{
	if(x==n+1)
	{
		int tans=0;
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(g[i][j])
				{
					if(mp[b[i]][b[j]]) continue;
					mp[b[i]][b[j]]=mp[b[j]][b[i]]=true,tans++;
				}
			}
		ans=ans>tans?ans:tans;
		return;
	}
	for(int i=1;i<=6;i++)
	{
		b[x]=i;
		dfs(x+1);
	}
}
int one()
{
	return 1;
}
int main()
{
	init();
	dfs(1);
	printf("%d",ans);
	return one()-one();
}

