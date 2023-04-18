#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt,value;
}e[600005],E[600005],tmp[300005];
int Head[300005],cnt=1,Ecnt,Ehead[300005],tmpnum,dfn[300005],low[300005],s[300005],dfncnt,num,top;
int col[300005],colnum;
bool usd[600005];
void add(int x,int y,int z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void Eadd(int x,int y,int z){
	++Ecnt;
	E[Ecnt].from=x;
	E[Ecnt].to=y;
	E[Ecnt].value=z;
	E[Ecnt].nxt=Ehead[x];
	Ehead[x]=Ecnt;
}
void tarjan(int now,int fa){
	dfn[now]=low[now]=++dfncnt;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==fa)continue;
		if(!dfn[to]){
			tarjan(to,now);
			low[now]=min(low[now],low[to]);
			if(low[to]>dfn[now])usd[i]=usd[i^1]=true;
		}
		else low[now]=min(low[now],dfn[to]);
	}
}
void dfs(int now,int pre){
	col[now]=colnum;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre||usd[i]||col[to])continue;
		dfs(to,now);
	}
}
bool cmp(edge a,edge b){
	return a.value>b.value;
}
int fa[300005];
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
}
int f[300005][25],depth[300005],sum[300005],psum[300005];
bool uusd[500005];
void dfs2(int now,int pre){
	f[now][0]=pre;
	uusd[now]=true;
	depth[now]=depth[pre]+1;
	sum[now]+=psum[now];
	for(int i=1;i<=20;++i)f[now][i]=f[f[now][i-1]][i-1];
	for(int i=Ehead[now];i;i=E[i].nxt){
		int to=E[i].to;
		if(to==pre)continue;
		sum[to]=sum[now];
		if(E[i].value)++sum[to];
		dfs2(to,now);
	}
}
int lca(int x,int y){
	if(depth[x]<depth[y])swap(x,y);
	for(int i=20;i>=0;--i)if(depth[f[x][i]]>=depth[y])x=f[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;--i){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i,0);
	for(int i=1;i<=n;++i)if(!col[i])++colnum,dfs(i,0);
	for(int i=2;i<=cnt;i+=2){
		if(col[e[i].from]!=col[e[i].to]){
			++tmpnum;
			tmp[tmpnum].from=col[e[i].from];
			tmp[tmpnum].to=col[e[i].to];
			tmp[tmpnum].value=e[i].value;
		}
		else{
			if(e[i].value)psum[col[e[i].from]]=1;
			else;
		}
	}
	sort(tmp+1,tmp+1+tmpnum,cmp);
	for(int i=1;i<=colnum;++i)fa[i]=i;
	for(int i=1;i<=tmpnum;++i){
		int x=tmp[i].from,y=tmp[i].to;
		int r1=getfa(x),r2=getfa(y);
		if(r1!=r2){
			Eadd(x,y,tmp[i].value);
			Eadd(y,x,tmp[i].value);
			Merge(r1,r2);
		}
	}
	for(int i=1;i<=colnum;++i)if(!uusd[i])dfs2(i,0);
	int q;
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int LCA=lca(col[x],col[y]);
		if(!LCA){
			printf("NO\n");
			continue;
		}
		if(sum[col[x]]+sum[col[y]]-2*sum[LCA]+psum[LCA]>=1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
