#include<bits/stdc++.h>
using namespace std;
const int INF=2147483647;
struct edge{
	int from,to,nxt;
}e[1000005];
int Head[500005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool usd[500005];
int degree[500005],depth[500005],fa[500005],tmp[500005],value[500005];
void tag(int x,int y){
	++tmp[y];
	--tmp[fa[x]];
}
int tot;
void dfs(int now,int pre){
	usd[now]=true;
	fa[now]=pre;
	depth[now]=depth[pre]+1;
	int ecnt=0,mindepth=INF,eto;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		if(usd[to]){
			if(depth[to]>depth[now])continue;
			++ecnt;
			if(depth[to]<mindepth){
				mindepth=depth[to];
				eto=to;
			}
		}
		else{
			dfs(to,now);
			value[now]+=value[to];
		}
	}
	if(ecnt==1){
		tag(eto,now);
		++tot;
	}
	else if(ecnt>2){
		tag(now,now);
		++tot;
	}
	else if(ecnt==2){
		tag(eto,eto);
		tag(now,now);
		++tot;
	}
	else;
	value[now]+=tmp[now];
}
bool isans[500005];
int ans[500005];
bool judgeusd[500005];
bool judge(int rt,int now,int pre){
	judgeusd[now]=true;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		if(judgeusd[to]&&to!=rt&&now!=rt)return false;
		if(judgeusd[to]&&to!=rt&&now==rt)continue;
		if(judgeusd[to]&&to==rt)continue;
		if(!judge(rt,to,now))return false;
	}
	return true;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int bugcnt=0;
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		++degree[u];
		++degree[v];
	}
	int Max=0;
	for(int i=1;i<=n;++i){
		Max=max(Max,degree[i]);
		if(degree[i]==2)++bugcnt;
	}
	for(int i=1;i<=n;++i)if(degree[i]%2)return !printf("0\n");
	dfs(1,0);
	int anscnt=0;
	for(int i=1;i<=n;++i)if(value[i]==tot&&degree[i]==Max)ans[++anscnt]=i;
	if(bugcnt!=n&&anscnt>2){
		while(1);
	}
	if(bugcnt!=n){
		memset(judgeusd,0,sizeof(judgeusd));
		int falsenum=0;
		for(int i=1;i<=anscnt;++i){
			isans[i]=judge(ans[i],ans[i],0);
			if(!isans[i])++falsenum;
		}
		if(anscnt-falsenum==2&&bugcnt!=n-2){
			while(1);
		}
		printf("%d\n",anscnt-falsenum);
		for(int i=1;i<=anscnt;++i)if(isans[i])printf("%d ",ans[i]);
		printf("\n");
	}
	else{
		printf("%d\n",n);
		for(int i=1;i<=n;++i)printf("%d ",i);
		printf("\n");
	}
	return 0;
}
