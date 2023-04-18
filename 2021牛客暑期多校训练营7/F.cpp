#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N=300005;
int n;
struct edge
{
	int from,to,nxt;
}e[N*2],E[N*2];
int cnt,Cnt,Head[N],Headd[N],fa[N],son[N],dep[N],sz[N],id[N],top[N],col[N<<2];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void addd(int x,int y)
{
	++Cnt;
	E[Cnt].from=x;
	E[Cnt].to=y;
	E[Cnt].nxt=Headd[x];
	Headd[x]=Cnt;
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		col[rt]=0;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	return;
}
void dfs1(int now,int pre,int depth)
{
	fa[now]=pre;
	dep[now]=depth;
	sz[now]=1;
	int Max=0;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs1(to,now,depth+1);
		sz[now]+=sz[to];
		if(sz[to]>Max)
		{
			Max=sz[to];
			son[now]=to;
		}
	}
}
int cntt;
void dfs2(int now,int topf)
{
	id[now]=++cntt;
	top[now]=topf;
	if(son[now])dfs2(son[now],topf);
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==fa[now]||to==son[now])continue;
		dfs2(to,to);
	}
}
void push_col(int l,int r,int rt)
{
	int m=(l+r)>>1;
	if(col[rt])
	{
		col[rt<<1]=col[rt<<1]+col[rt];
		col[rt<<1|1]=col[rt<<1|1]+col[rt];
		col[rt]=0;
	}
}
void modify(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(l>=nowl&&r<=nowr)
	{
		col[rt]=col[rt]+k;
		return;
	}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(m>=nowl)modify(lson,nowl,nowr,k);
	if(m<nowr)modify(rson,nowl,nowr,k);
	return;
}
int query(int l,int r,int rt,int pos)
{
	if(l==r)return col[rt];
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(pos<=m)return query(lson,pos);
	else return query(rson,pos);
}
void modifyrange(int x,int y,int k)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		modify(1,n,1,id[top[x]],id[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	modify(1,n,1,id[x],id[y],k);
}
int ans,tmpnext[N],maxans[N];
void dfss(int now,int pre){
	maxans[now]=1;
	for(int i=Headd[now];i;i=E[i].nxt){
		int to=E[i].to;
		if(to==pre)continue;
		dfss(to,now);
		maxans[now]=max(maxans[now],maxans[to]+1);
	}
}
void dfs(int top,int now,int pre,int nowans){
	ans=max(ans,nowans);
	if(ans>=maxans[top])return;
	for(int i=Headd[now];i;i=E[i].nxt){
		int to=E[i].to;
		if(to==pre)continue;
		int tmp=query(1,n,1,id[to]);
		if(!tmp){
			tmpnext[now]=to;
			modifyrange(1,to,1);
			modify(1,n,1,id[to],id[to]+sz[to]-1,1);
			dfs(top,to,now,nowans+1);
			modifyrange(1,to,-1);
			modify(1,n,1,id[to],id[to]+sz[to]-1,-1);
		}
		else{
			if(now!=top){
				modifyrange(1,top,-1);
				modify(1,n,1,id[top],id[top]+sz[top]-1,-1);
				dfs(tmpnext[top],now,pre,nowans-1);
				modifyrange(1,top,1);
				modify(1,n,1,id[top],id[top]+sz[top]-1,1);
			}
			else{
				modifyrange(1,top,-1);
				modify(1,n,1,id[top],id[top]+sz[top]-1,-1);
				modifyrange(1,to,1);
				modify(1,n,1,id[to],id[to]+sz[to]-1,1);
				dfs(to,to,now,nowans);
				modifyrange(1,top,1);
				modify(1,n,1,id[top],id[top]+sz[top]-1,1);
				modifyrange(1,to,-1);
				modify(1,n,1,id[to],id[to]+sz[to]-1,-1);
			}
		}
	}
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		build(1,n,1);
		cnt=Cnt=ans=cntt=0;
		for(int i=1;i<=n;++i)Head[i]=Headd[i]=tmpnext[i]=0;
		for(int i=1;i<=n;++i)fa[i]=id[i]=top[i]=son[i]=dep[i]=sz[i]=0;
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			addd(x,y);
			addd(y,x);
		}
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		dfs1(1,0,1);
		dfs2(1,1);
		modify(1,n,1,id[1],id[1]+sz[1]-1,1);
		dfss(1,0);
		dfs(1,1,0,1);
		cout<<ans<<endl;
	}
	
	return 0;
}
