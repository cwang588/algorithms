#include<bits/stdc++.h>
using namespace std;
int n,k;
struct edge
{
	int from,to,nxt;
	long long v;
}e[400005];
int Head[200005],cnt;
void add(int x,int y,long long z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
long long sum[200005],sum1[200005];
struct point
{
	int to;
	long long tot;
	bool operator < (const point &a)const
	{
		return tot>a.tot;
	}
};
vector<point>v[200005];
void dfs1(int now,int pre)
{
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs1(to,now);
		v[now].push_back(point{to,sum1[to]+e[i].v});
		sum[to]=e[i].v;
	}
	sort(v[now].begin(),v[now].end());
	sum1[now]=0;
	int len=v[now].size();
	len=min(len,k-1);
	for(int i=0;i<len;++i)
		sum1[now]+=v[now][i].tot;
}
long long ans;
void dfs2(int now,int pre,long long tot)
{
	if(pre)v[now].push_back(point{pre,tot});
	sort(v[now].begin(),v[now].end());
	long long tmp=0;
	int len=v[now].size();
	for(int i=0;i<len;++i)tmp+=v[now][i].tot; 
	ans=max(ans,tmp);
	tmp=0;
	int lenn=min(len,k);
	for(int i=0;i<lenn;++i)tmp+=v[now][i].tot;
	for(int i=0;i<len;++i)
	{
		int to=v[now][i].to;
		if(to==pre)continue;
		long long ttt;
		if(i<lenn)ttt=tmp-sum1[to];
		else ttt=tmp-v[now][k-1].tot+sum[to];
		dfs2(to,now,ttt);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ans=cnt=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)Head[i]=0,v[i].clear();
		for(int i=1;i<n;++i)
		{
			int x,y;
			long long z;
			scanf("%d%d%lld",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}
		if(!k)
		{
			printf("0\n");
			continue;
		}
		dfs1(1,0);
		dfs2(1,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
