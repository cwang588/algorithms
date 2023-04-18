#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
	long long val;
}e[500005];
int Head[250005],cnt;
stack<int>s;
void add(int x,int y,long long z)
{
	++cnt;
	e[cnt].from=x;	
	e[cnt].to=y;	
	e[cnt].val=z;	
	e[cnt].nxt=Head[x];	
	Head[x]=cnt;
}
int dfin[250005],dfout[250005],indnow,n;
long long dismin[250005],ans[250005];
int depth[500005],f[500005][25],lg[500005];
void dfs2(int now,int pre)
{
	f[now][0]=pre;
	for(int i=1;(1<<i)<=depth[now];++i)f[now][i]=f[f[now][i-1]][i-1];
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to==pre)continue;
		depth[e[i].to]=depth[now]+1;
		dfs2(e[i].to,now);
	}
}
void dfs1(int now,int pre)
{
	dfin[now]=++indnow;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dismin[to]=min(dismin[now],e[i].val);
		dfs1(to,now);
	}
	dfout[now]=++indnow;
}
void init()
{
	for(int i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);
}
int lca(int x,int y)
{
	if(depth[x]<depth[y])swap(x,y);
	while(depth[x]>depth[y])x=f[x][lg[depth[x]-depth[y]]-1];
	if(x==y)return x;
	for(int k=lg[depth[x]]-1;k>=0;--k)
	{
		if(f[x][k]!=f[y][k])
		{
			x=f[x][k];
			y=f[y][k];
		}
	}
	return f[x][0];
}
int ind[500005];
bool cmp(int x,int y)
{
	int k1=x>0?dfin[x]:dfout[-x];
	int k2=y>0?dfin[y]:dfout[-y];
	return k1<k2;
}
bool usd[500005];
int main()
{
	int m;
	scanf("%d",&n);
	init();
	for(int i=1;i<n;++i)
	{
		int x,y;
		long long z;
		scanf("%d%d%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dismin[1]=9223372036854775807;
	dfs1(1,0);
	dfs2(1,0);
	scanf("%d",&m);
	while(m--)
	{
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;++i)scanf("%d",&ind[i]),usd[ind[i]]=true,ans[ind[i]]=dismin[ind[i]];
		int tot=k;
		sort(ind+1,ind+tot+1,cmp);
		for(int i=1;i<k;++i)
		{
			int now=lca(ind[i],ind[i+1]);
			if(!usd[now])ind[++tot]=now,usd[now]=true;
		}
		int tott=tot;
		for(int i=1;i<=tott;++i)ind[++tot]=-ind[i];
		if(!usd[1])ind[++tot]=1,ind[++tot]=-1,usd[1]=true;
		sort(ind+1,ind+tot+1,cmp);
		for(int i=1;i<=tot;++i)
		{
			if(ind[i]>0)s.push(ind[i]);
			else
			{
				int now=s.top();
				s.pop();
				if(now==1)printf("%lld\n",ans[1]);
				else ans[s.top()]+=min(ans[now],dismin[now]);
				ans[now]=0;
				usd[now]=false;
			}
		}
	}
	return 0;
}
