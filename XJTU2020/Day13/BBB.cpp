# include <iostream>
# include <cstdio>
# include <cstring>
# include <queue>
# define sz 20
# define FOR(i,st,ed) for(int i=st;i<=ed;++i)
# define _FOR(tu,u) for(int v,i=tu.hd[u];i;i=tu.e[i].nt)
# define _(tu) v=tu.e[i].to;
using namespace std;
int re()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+ch-'0';ch=getchar();}
	return s*f;
}
const int N=2e5+7;
struct MAP
{
	struct edge
	{
		int to,nt;
	}e[N<<1];int cnt,hd[N];
	void link(int x,int y)
	{
		e[++cnt]=(edge){y,hd[x]};hd[x]=cnt;
	}
}xx,a,ra,t,rt,z;
int n,m;
int dfn[N],dji,id[N],ff[N];
void dfs(int u)
{
	id[dfn[u]=++dji]=u;
	_FOR(a,u){
		_(a);
		if(!dfn[v]) dfs(v),ff[v]=u,t.link(u,v); 
	}
}
int anc[N],semi[N],mn[N];
void init()
{
	FOR(i,1,n) anc[i]=semi[i]=mn[i]=i;
}
int find(int u)
{
	if(u!=anc[u])
	{
		int t=anc[u];anc[u]=find(anc[u]);
		if(dfn[semi[mn[u]]]>dfn[semi[mn[t]]]) mn[u]=mn[t];
	}
	return anc[u];
}
void len_tarjan()
{
	init();
	for(int j=n;j>=2;--j)
	{
		int u=id[j],res=j;
		if(!u) continue;
		_FOR(ra,u)
		{
			_(ra);
			if(!dfn[v]) continue;
			if(dfn[v]<dfn[u]) res=min(res,dfn[v]);
			else find(v),res=min(res,dfn[semi[mn[v]]]);
		}
		semi[u]=id[res];anc[u]=ff[u];t.link(semi[u],u); 
	}
}
int ru[N],dep[N],fa[N][25];
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int del=dep[x]-dep[y];
	FOR(i,0,sz)
		if((1<<i)&del) x=fa[x][i];
	if(x==y) return x;
	for(int i=sz;i>=0;--i)
		if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void work(int u)
{
	int t=rt.e[rt.hd[u]].to;
	_FOR(rt,u){
		_(rt);t=lca(t,v);
	}
	dep[u]=dep[t]+1;
	fa[u][0]=t;
	z.link(t,u);
	FOR(i,1,sz)
		fa[u][i]=fa[fa[u][i-1]][i-1]; 
}
void tpsort(){
	FOR(j,1,n)
		_FOR(t,j){
			_(t);
			ru[v]++;rt.link(v,j); 
		}	
	FOR(i,1,n) if(!ru[i]) t.link(0,i),rt.link(i,0);
	queue <int> q;q.push(0);
	while(q.size()){
		int u=q.front();q.pop();
		_FOR(t,u){
			_(t);
			if((--ru[v])<=0) q.push(v),work(v);
		}
	} 
}

int siz[N];
void adfs(int u){
	siz[u]=1;
	_FOR(z,u){
		_(z);adfs(v);siz[u]+=siz[v];
	}
}//最后adfs用来搜答案
int main(){
	n=re();m=re();int x,y;
	FOR(i,1,m){
		x=re();y=re();
		a.link(x,y);ra.link(y,x);  
	}
	dfs(1);
	len_tarjan();
	tpsort();
	adfs(0);
	FOR(i,1,n) cout<<siz[i]<<' ';
	return 0;
}
