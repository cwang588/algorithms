#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[200005];
int Head[100005],cnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int in[100005],out[100005],tot,a[200005],col[100005],colnum[100005];
struct query
{
	int l,r,lw,rw,ans,id;
}q[100005];
void dfs(int now,int pre)
{
	++tot;
	in[now]=tot;
	a[tot]=now;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to==pre)continue;
		dfs(e[i].to,now);
	}
	++tot;
	out[now]=tot;
	a[tot]=now;
}
bool cmp1(query x,query y)
{
	return (x.lw==y.lw)?(x.rw<y.rw):(x.lw<y.lw);
}
bool cmp2(query x,query y)
{
	return x.id<y.id;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&col[i]);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	int base=sqrt(2*n);
	for(int i=1;i<=m;++i)
	{
		int x;
		scanf("%d",&x);
		q[i].l=in[x];
		q[i].lw=in[x]/base;
		q[i].r=out[x];
		q[i].rw=out[x]/base;
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp1);
	int l=0,r=0,ansnow=0;
	for(int i=1;i<=m;++i)
	{
		while(r<q[i].r)
		{
			++r;
			++colnum[col[a[r]]];
			if(colnum[col[a[r]]]==1)++ansnow;
		}
		while(l>q[i].l)
		{
			--l;
			++colnum[col[a[l]]];
			if(colnum[col[a[l]]]==1)++ansnow;			
		}
		while(r>q[i].r)
		{
			--colnum[col[a[r]]];
			if(!colnum[col[a[r]]])--ansnow;
			--r;
		}
		while(l<q[i].l)
		{
			--colnum[col[a[l]]];
			if(!colnum[col[a[l]]])--ansnow;
			++l;			
		}		
		q[i].ans=ansnow;
	}
	sort(q+1,q+1+m,cmp2);
	for(int i=1;i<=m;++i)printf("%d\n",q[i].ans);
	return 0;
}
