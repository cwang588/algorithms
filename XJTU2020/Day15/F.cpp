#include<bits/stdc++.h>
using namespace std;
const long long inf=19198101926081700;
long long a[100005],b[100005],sum[100005],dp[100005][2],son[100005][2],tmp[100005][2],num[100005][2],sonnum[100005];
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
void dfs1(int now,int pre)
{
	long long tmp1=-inf,tmp2=inf;
	sonnum[now]=0;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		++sonnum[now];
		dfs1(to,now);
		if(dp[to][0]<tmp2)
		{
			tmp2=dp[to][0];
			dp[now][1]=dp[to][0];
			son[now][1]=to;
			num[now][1]=1;
		}
		else if(dp[to][0]==tmp2)++num[now][1];
		else;
		if(dp[to][1]>tmp1)
		{
			tmp1=dp[to][1];
			dp[now][0]=dp[to][1];
			son[now][0]=to;
			num[now][0]=1;
		}
		else if(dp[to][1]==tmp1)++num[now][0];
		else;
	}
	if(num[now][0]>1)tmp[now][0]=dp[now][0];
	else
	{
		tmp[now][0]=-inf;
		for(int i=Head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if(to==pre)continue;
			if(dp[to][1]<dp[now][0])tmp[now][0]=max(tmp[now][0],dp[to][1]);
		}
	}
	if(num[now][1]>1)tmp[now][1]=dp[now][1];
	else
	{
		tmp[now][1]=inf;
		for(int i=Head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if(to==pre)continue;
			if(dp[to][0]>dp[now][1])tmp[now][1]=min(tmp[now][1],dp[to][0]);
		}
	}
	tmp[now][0]+=sum[now];
	tmp[now][1]+=sum[now];
	dp[now][0]+=sum[now];
	dp[now][1]+=sum[now];
}
void dfs2(int now,int pre)
{
	if(!sonnum[now])
	{
		if(sonnum[pre]==1&&pre==1)
		{
			dp[now][0]=dp[now][1]=sum[now]+sum[1];
			return;
		}
		if(num[pre][1]==1&&son[pre][1]==now)dp[now][0]=tmp[pre][1]+sum[now];
		else dp[now][0]=dp[pre][1]+sum[now];
		if(num[pre][0]==1&&son[pre][0]==now)dp[now][1]=tmp[pre][0]+sum[now];
		else dp[now][1]=dp[pre][0]+sum[now];
		return;
	}
	if(pre)
	{
		if(sonnum[pre]==1&&pre==1)
		{
			if(dp[now][0]<sum[1]+sum[now])
			{
				tmp[now][0]=dp[now][0];
				dp[now][0]=sum[1]+sum[now];
				num[now][0]=1;
				son[now][0]=1;
			}
			else if(dp[now][0]==sum[1]+sum[now])++num[now][0],tmp[now][0]=sum[1]+sum[now];
			else tmp[now][0]=sum[1]+sum[now];
			if(dp[now][1]>sum[1]+sum[now])
			{
				tmp[now][1]=sum[1]+sum[now];
				dp[now][1]=sum[1]+sum[now];
				num[now][1]=1;
				son[now][1]=1;
			}
			else if(dp[now][1]==sum[1]+sum[now])++num[now][1],tmp[now][1]=sum[1]+sum[now];
			else tmp[now][1]=sum[1]+sum[now];
		}
		else
		{	
			if(num[pre][1]==1&&son[pre][1]==now)
			{
				if(dp[now][0]<tmp[pre][1]+sum[now])
				{
					tmp[now][0]=dp[now][0];
					dp[now][0]=tmp[pre][1]+sum[now];
					son[now][0]=pre;
					num[now][0]=1;
				}
				else if(dp[now][0]==tmp[pre][1]+sum[now])
				{
					++num[now][0];
					tmp[now][0]=dp[now][0];
				}
				else tmp[now][0]=max(tmp[now][0],tmp[pre][1]+sum[now]);
			}
			else
			{
				if(dp[now][0]<dp[pre][1]+sum[now])
				{
					tmp[now][0]=dp[pre][1]+sum[now];
					dp[now][0]=dp[pre][1]+sum[now];
					son[now][0]=pre;
					num[now][0]=1;
				}
				else if(dp[now][0]==dp[pre][1]+sum[now])++num[now][0],tmp[now][0]=dp[now][0];
				else tmp[now][0]=max(tmp[now][0],dp[pre][1]+sum[now]);
			}
			if(num[pre][0]==1&&son[pre][0]==now)
			{
				if(dp[now][1]>tmp[pre][0]+sum[now])
				{
					tmp[now][1]=dp[now][1];
					dp[now][1]=tmp[pre][0]+sum[now];
					son[now][1]=pre;
					num[now][1]=1;
				}
				else if(dp[now][1]==tmp[pre][0]+sum[now])++num[now][1],tmp[now][1]=dp[now][1];
				else tmp[now][1]=min(tmp[now][1],tmp[pre][0]+sum[now]);
			}
			else
			{
				if(dp[now][1]>dp[pre][0]+sum[now])
				{
					tmp[now][1]=dp[now][1];
					dp[now][1]=dp[pre][0]+sum[now];
					son[now][1]=pre;
					num[now][1]=1;
				}
				else if(dp[now][1]==dp[pre][0]+sum[now])++num[now][1],tmp[now][1]=dp[now][1];
				else tmp[now][1]=min(tmp[now][1],dp[pre][0]+sum[now]);
			}
		}
	}
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs2(to,now);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)Head[i]=son[i][0]=son[i][1]=dp[i][0]=dp[i][1]=tmp[i][0]=tmp[i][1]=num[i][0]=num[i][1]=0;
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		for(int i=1;i<=n;++i)scanf("%lld",&b[i]);
		for(int i=1;i<=n;++i)sum[i]=a[i]-b[i];
		for(int i=1;i<n;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x); 
		}
		dfs1(1,0);
		dfs2(1,0);
		long long ans=-inf;
		for(int i=1;i<=n;++i)ans=max(ans,dp[i][1]);
		printf("%lld\n",ans);
	}
	return 0;
}
