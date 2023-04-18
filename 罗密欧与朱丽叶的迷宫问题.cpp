#include<bits/stdc++.h>
using namespace std;
bool usd[105][105];
int n,m,k,p,q,r,s,Min=2147483647,cnt;
int Now[105][105],ans[105][105];
int mov[8][2]={{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
void dfs(int x,int y,int now,int tot,int last)
{
	if(x==r&&y==s)
	{
		if(now>Min)return;
		if(now==Min)++cnt;
		else 
		{
			cnt=1;
			Min=now;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					ans[i][j]=Now[i][j];
		}
		return;
	}
	for(int i=0;i<=7;++i)
	{
		if(i==last)continue;
		for(int j=1;;++j)
		{
			int tox=x+mov[i][0]*j,toy=y+mov[i][1]*j;
			if(tox<=0||tox>n||toy<=0||toy>m||usd[tox][toy]||Now[tox][toy])break;
			if(tox==r&&toy==s&&n*m-k!=tot+j)break;
			for(int k=1;k<=j;++k)
			{
				int toxx=x+mov[i][0]*k,toyy=y+mov[i][1]*k;
				Now[toxx][toyy]=tot+k;
			}
			dfs(tox,toy,now+1,tot+j,i);
			for(int k=1;k<=j;++k)
			{
				int toxx=x+mov[i][0]*k,toyy=y+mov[i][1]*k;
				Now[toxx][toyy]=0;
			}	
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		usd[x][y]=true;
	}
	scanf("%d%d%d%d",&p,&q,&r,&s);
	Now[p][q]=1;
	dfs(p,q,0,1,-1);
	if(Min<2147483647)
	{
		printf("%d\n%d\n",Min-1,cnt);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				printf("%d ",ans[i][j]>0?ans[i][j]:-1);
			printf("\n");
		}
	}
	else printf("No Solution!\n");
	return 0;
}
