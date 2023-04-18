#include<bits/stdc++.h>
#define maxn 20005
using namespace std;
int ans;
struct edge
{
	int from,to,nxt,v;
}e[2*maxn];
int Head[maxn],cnt,dp[maxn][3];
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
} 
void dfs(int now,int pre)
{
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to!=pre)
		{
			dfs(e[i].to,now);
			int t=e[i].v%3;
			++dp[now][t];
			if(!t)
			{
				dp[now][0]+=dp[e[i].to][0];
				dp[now][1]+=dp[e[i].to][1];
				dp[now][2]+=dp[e[i].to][2];
			}
			else if(t==1)
			{
				dp[now][0]+=dp[e[i].to][2];
				dp[now][1]+=dp[e[i].to][0];
				dp[now][2]+=dp[e[i].to][1];				
			}
			else
			{
				dp[now][0]+=dp[e[i].to][1];
				dp[now][1]+=dp[e[i].to][2];
				dp[now][2]+=dp[e[i].to][0];
			}
		}		
	}
	ans+=2*dp[now][0];
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to!=pre)
		{
			int t=e[i].v%3;
			if(!t)
			{
				ans+=(dp[e[i].to][0]+1)*(dp[now][0]-dp[e[i].to][0]-1);
				ans+=dp[e[i].to][1]*(dp[now][2]-dp[e[i].to][2]);
				ans+=dp[e[i].to][2]*(dp[now][1]-dp[e[i].to][1]);
			}
			else if(t==1)
			{
				ans+=dp[e[i].to][2]*(dp[now][0]-dp[e[i].to][0]);
				ans+=(dp[e[i].to][0]+1)*(dp[now][2]-dp[e[i].to][2]);
				ans+=dp[e[i].to][1]*(dp[now][1]-dp[e[i].to][1]-1);
			}
			else
			{
				ans+=dp[e[i].to][1]*(dp[now][0]-dp[e[i].to][0]);
				ans+=dp[e[i].to][2]*(dp[now][2]-dp[e[i].to][2]-1);
				ans+=(dp[e[i].to][0]+1)*(dp[now][1]-dp[e[i].to][1]);
			}
		}
	}
}
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	dfs(1,0);
	ans+=n;
	int g=gcd(ans,n*n);
	printf("%d/%d",ans/g,n*n/g);
	return 0;
}
