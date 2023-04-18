#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int n,m,Q;
int fa[600005],u[300005],v[300005];
int getfa(int x){
	if(x!=fa[x])fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
}
struct Query{
	int type,pos;
}q[500005];
bool usd[300005];
int value[600005],num,valuepos[600005];
struct edge{
	int from,to,nxt;
}e[2000005],ee[600005];
int Head[600005],cnt,cntt,Headd[600005],root[600005],lg[600005];
int depth[600005],f[600005][25];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void addd(int x,int y){
	++cntt;
	ee[cntt].from=x;
	ee[cntt].to=y;
	ee[cntt].nxt=Headd[x];
	Headd[x]=cntt;
}
bool vis[500005];
void dfs(int now,int pre){
	fa[now]=num;
	vis[now]=true;
	add(now,num);
	add(num,now);
	for(int i=Headd[now];i;i=ee[i].nxt){
		int to=ee[i].to;
		if(to==pre||vis[to])continue;
		dfs(to,now);
	}
}
int dfn[600005],sz[600005],tmpcnt,seq[600005];
void dfss(int now,int pre){
	f[now][0]=pre;
	dfn[now]=++tmpcnt;
	seq[tmpcnt]=now;
	sz[now]=1;
	for(int i=1;(1<<i)<=depth[now];++i)f[now][i]=f[f[now][i-1]][i-1];
	for(int i=Head[now];i;i=e[i].nxt){
		if(e[i].to==pre)continue;
		depth[e[i].to]=depth[now]+1;
		dfss(e[i].to,now);
		sz[now]+=sz[e[i].to];
	}
}
int Max[600005<<2];
void build(int l,int r,int rt){
	if(l==r){
		Max[rt]=value[seq[l]];
		return;
	} 
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
void modify(int l,int r,int rt,int pos){
	if(l==r){
		Max[rt]=0;
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)modify(lson,pos);
	else modify(rson,pos);
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
int query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return Max[rt];
	int m=(l+r)>>1,re=0;
	if(m>=nowl)re=max(re,query(lson,nowl,nowr));
	if(m<nowr)re=max(re,query(rson,nowl,nowr));
	return re;
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=3*n;++i)fa[i]=i;
	for(int i=1;i<=n;++i)scanf("%d",&value[i]),valuepos[value[i]]=i;
	for(int i=1;i<=m;++i)scanf("%d%d",&u[i],&v[i]);
	for(int i=1;i<=Q;++i){
		scanf("%d%d",&q[i].type,&q[i].pos);	
		if(q[i].type==2)usd[q[i].pos]=true;
	}
	num=n;
	for(int i=1;i<=m;++i){
		if(!usd[i]){
			addd(u[i],v[i]); 
			addd(v[i],u[i]); 
		}
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			++num;
			dfs(i,0);
		}
	}
	for(int i=Q;i>=1;--i){
		if(q[i].type==2){
			int r1=getfa(u[q[i].pos]),r2=getfa(v[q[i].pos]);
			if(r1!=r2){
				++num;
				fa[r1]=fa[r2]=num;
				add(r1,num);
				add(r2,num);
				add(num,r1);
				add(num,r2);
			}
		}
		else root[i]=getfa(q[i].pos);
	}
	++num;
	for(int i=1;i<num;++i){
		fa[i]=getfa(i);
		if(fa[i]==i){
			fa[i]=num;
			add(i,num);
			add(num,i);
		}
	}
	dfss(num,0);
	build(1,num,1);
	for(int i=1;i<=Q;++i){
		if(q[i].type==1){
			int ans=query(1,num,1,dfn[root[i]],dfn[root[i]]+sz[root[i]]-1);
			printf("%d\n",ans);
			if(ans)modify(1,num,1,dfn[valuepos[ans]]);
		}
	}
	return 0;
}
