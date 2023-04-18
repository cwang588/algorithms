#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
struct edge
{
	int from,to,nxt;
}e[2*maxn];
int Head[maxn],cnt,dp[maxn][3];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
} 
void dfs(int now,int pre)
{
	dp[now][2]=1;
	dp[now][1]=214748364;
	dp[now][0]=0;
	bool ky=false;
	for(int i=Head[now];i;i=e[i].nxt)
		if(e[i].to!=pre)
		{
			ky=true;
			dfs(e[i].to,now);
			dp[now][0]+=dp[e[i].to][1];
			dp[now][2]+=min(dp[e[i].to][0],min(dp[e[i].to][1],dp[e[i].to][2]));
		}
	if(!ky)return;
	int t=2147483647;
	for(int i=Head[now];i;i=e[i].nxt)
		if(e[i].to!=pre)
		{
			int tep=dp[e[i].to][2];
			for(int j=Head[now];j;j=e[j].nxt)
			{
				if(e[j].to!=pre&&i!=j)
					tep+=min(dp[e[j].to][1],dp[e[j].to][2]);
			}
			t=min(tep,t);
		}
	dp[now][1]=t;
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
	dfs(1,0);
	printf("%d\n",min(dp[1][1],dp[1][2]));
	return 0;
}
