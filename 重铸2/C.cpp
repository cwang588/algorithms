#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[2000005],E[2000005];
int Head[1000005],cnt,dfn[1000005],low[1000005],dfncnt;
int Headd[1000005],cntt;
int col[1000005],colcnt,ans[1000005],root,maxd;
bool usd[2000005],vis[1000005],bkx[1000005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void addE(int x,int y){
	++cntt;
	E[cntt].from=x;
	E[cntt].to=y;
	E[cntt].nxt=Headd[x];
	Headd[x]=cntt;
}
void tarjan(int now,int fa,int dep){
	dfn[now]=low[now]=++dfncnt;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==fa)continue;
		if(!dfn[to]){
			tarjan(to,now,dep+1);
			if(low[now]>low[to])low[now]=low[to];
			if(low[to]>dfn[now])usd[i]=true;
		}
		else{
			if(low[now]>dfn[to])low[now]=dfn[to];
		}
	}
}
bool judge(int x){
	if(x%2)return usd[x]|usd[x+1];
	return usd[x]|usd[x-1];
}
void dfs(int now,int fa){
	vis[now]=true;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(vis[to]||judge(i))continue;
		col[to]=col[now];
		dfs(to,now);
	}
}
void dfss(int now,int fa,int dep){
	//assert(!bkx[now]);
	if(bkx[now]){
		printf("%d %d\n",now,dep);
		getchar();
	}
	if(maxd<dep){
		maxd=dep;
		root=now;
	}
	bkx[now]=true;
	for(int i=Headd[now];i;i=E[i].nxt){
		int to=E[i].to;
		if(to==fa)continue;
		dfss(to,now,dep+1);
	}
}
int main(){
	freopen("007","r",stdin);
	freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		++x;
		++y;
		add(x,y);
		add(y,x);
		assert(x<=n);
		assert(y<=n);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i,0,0);
	for(int i=1;i<=n;++i){
		if(!col[i]){
			col[i]=++colcnt;
			dfs(i,0);
		}
	}
	for(int i=1;i<=cnt;++i){
		int x=e[i].from,y=e[i].to;
	  	//if(!usd[i])continue;
	  	if(col[x]==col[y])continue;
		addE(col[x],col[y]);
		addE(col[y],col[x]);
	}
	for(int i=1;i<=colcnt;++i){
		if(!bkx[i]){
			maxd=0;
			dfss(i,0,1);
			memset(bkx,0,sizeof(bkx));
			maxd=0;
			dfss(root,0,1);
			ans[i]=maxd;
		}
	}
	int num=0,tot=0;
	for(int i=1;i<=colcnt;++i){
		if(!ans[i])continue;
		tot+=ans[i]-1;
		++num;
	}
	cout<<tot+num-1<<"\n";
	return 0;
}
