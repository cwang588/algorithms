#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[600005];
int Head[300005],cnt,dfn[300005],low[300005],s[300005],dfncnt,num,top;
int col[300005],colcnt;
bool usd[300005];
vector<int>unicom[300005];
int fa[300005],linksz[300005];
int anscnt[300005];
bool gd[300005];
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
	linksz[y]+=linksz[x];
}
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void tarjan(int now,int root){
	dfn[now]=low[now]=++dfncnt;
	s[++top]=now;
	if(now==root&&!Head[now]){
		unicom[++num].push_back(now);
		return;
	}
	int sz=0;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(!dfn[to]){
			tarjan(to,root);
			low[now]=min(low[now],low[to]);
			if(low[to]>=dfn[now]){
				if(now!=root)usd[now]=true;
				++num;
				while(s[top+1]!=to)unicom[num].push_back(s[top]),--top;
				unicom[num].push_back(now);
				gd[now]=true;
			}
			++sz;
		}
		else low[now]=min(low[now],dfn[to]);
	}
	if(now==root&&sz>1)usd[now]=true;
}
set<int>ss;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i,linksz[i]=1;
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y)continue;
		int r1=getfa(x),r2=getfa(y);
		if(r1!=r2)Merge(r1,r2);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;++i)fa[i]=getfa(i);
	int tmpnum=0;
	for(int i=1;i<=n;++i)if(fa[i]==i)++tmpnum;
	for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i,i);
	for(int i=1;i<=num;++i){
		for(auto x:unicom[i])++anscnt[x];
	}
	for(int i=1;i<=n;++i){
		if(!gd[i]){
			if(linksz[fa[i]]==1)printf("%d ",tmpnum-1);
			else printf("%d ",tmpnum);
		}
		else printf("%d ",anscnt[i]+tmpnum-1);
	}
	printf("\n");
	return 0;
}
