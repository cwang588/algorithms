#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[200005];
int cnt,Head[100005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int dp[100005][3],sz[100005];
void dfs1(int now,int pre)
{
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs1(to,now);
		++sz[now];
	}
}
void dfs2(int now,int pre)
{
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs2(to,now);
	}	
	int tmp0=0,tmp1=0,tmp2=0,tmp3=-9999999;
	int num=0;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		if(!sz[to])++num;
		tmp0+=dp[to][0];
		tmp1+=dp[to][1];
		tmp2+=dp[to][2];
		tmp3=max(tmp3,dp[to][2]-dp[to][1]);
}
	if(sz[now]>0)
	{
		if(num>1)dp[now][0]=dp[now][1]=dp[now][2]=tmp1+1;
		else if(num==1)
		{
			dp[now][0]=dp[now][1]=dp[now][2]=tmp1+1;
			dp[now][1]=min(dp[now][1],tmp2-tmp3);
		}	
		else
		{
			dp[now][0]=dp[now][1]=dp[now][2]=tmp1+1;
			dp[now][0]=min(dp[now][0],tmp2);
			dp[now][1]=min(dp[now][1],tmp2-tmp3);
			dp[now][2]=min(dp[now][2],tmp2);
		}
	}
	else 
	{
		dp[now][0]=dp[now][1]=0;
		dp[now][2]=1;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%d\n",min(dp[1][0],dp[1][2]));
	return 0;
}
