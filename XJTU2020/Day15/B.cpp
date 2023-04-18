#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> >s;
struct edge
{
	int from,to,nxt,v;
}e[600005],E[200005],tmp[100005];
int cnt,Head[300005],sum[300005],num;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int fa[100005];
int lg[500005],depth[500005],f[500005][20];
int getfa(int x)
{
	if(x!=fa[x])fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){fa[x]=y;}
bool cmp(edge a,edge b){return a.v<b.v;}
void dfs(int now,int pre)
{
	f[now][0]=pre;
	for(int i=1;(1<<i)<=depth[now];++i)f[now][i]=f[f[now][i-1]][i-1];
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to==pre)continue;
		depth[e[i].to]=depth[now]+1;
		dfs(e[i].to,now);
	}
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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		s.clear();
		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);
		cnt=0;
		for(int i=1;i<=n*3;++i)fa[i]=i,Head[i]=0;
		for(int i=1;i<=3*n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);
		for(int i=1;i<=m;++i)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(x>y)swap(x,y);
			E[i]={x,y,0,z};
			s.insert(make_pair(x,y));
		}
		sort(E+1,E+1+m,cmp);
		num=n;
		int tmpnum=0;
		for(int i=1;i<=m;++i)
		{
			int x=E[i].from,y=E[i].to,r1=getfa(x),r2=getfa(y);
			if(r1!=r2)
			{
				tmp[++tmpnum]=E[i];
				Merge(r1,r2);
			}
		}
		for(int i=tmpnum;i>=1;--i)
		{
			int x=tmp[i].from,y=tmp[i].to,r1=getfa(x),r2=getfa(y);
			++num;
			add(num,x);
			add(x,num);
			add(num,y);
			add(y,num);
			sum[num]=tmp[i].v;
			Merge(r1,num);
			Merge(r2,num);
		}
		for(int i=1;i<=num;++i)fa[i]=getfa(i);
		for(int i=1;i<=3*n;++i)
		{
			if(fa[i]==i)
			{
				depth[i]=0;
				dfs(i,0);
			}
		}
		for(int i=1;i<=q;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(x>=y)swap(x,y);
			if(s.count(make_pair(x,y)))printf("0\n");
			else
			{
				int r1=getfa(x),r2=getfa(y);
				if(r1!=r2)printf("-1\n");
				else printf("%d\n",sum[lca(x,y)]);
			}
		}
	}
	return 0;
} 
