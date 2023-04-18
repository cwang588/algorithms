#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
	long long value;
}e[400005],E[200005];
int cnt=1,Head[100005];
int cntt,Headd[100005];
void add(int x,int y,long long z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void addd(int x,int y){
	++cntt;
	E[cntt].from=x;
	E[cntt].to=y;
	E[cntt].nxt=Headd[x];
	Headd[x]=cntt;
}
int dfn[100005],low[100005],dfncnt;
bool usd[400005];
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
int colcnt,col[100005],num[100005];
void dfs(int now){
	col[now]=colcnt;
	for(int i=Head[now];i;i=e[i].nxt){
		if(usd[i]||col[e[i].to])continue;
		dfs(e[i].to);
	}
}
int tot[100005];
void dfss(int now,int pre){
	tot[now]=num[now];
	for(int i=Headd[now];i;i=E[i].nxt){
		int to=E[i].to;
		if(to==pre)continue;
		dfss(to,now);
		tot[now]+=tot[to]+1;
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	long long sum=0;
	for(int i=1;i<=m;++i){
		int x,y;
		long long z;
		cin>>x>>y>>z;
		sum+=z;
		add(x,y,z);
		add(y,x,z);
	}
	if(m%2==0)cout<<sum;
	else{
		tarjan(1,0);
		long long tmp=2000000000;
		for(int i=1;i<=n;++i){
			if(!col[i]){
				++colcnt;
				dfs(i);
			}
		}
		for(int i=2;i<=cnt;i+=2){
			if(col[e[i].from]==col[e[i].to])++num[col[e[i].from]];
			else{
				addd(col[e[i].from],col[e[i].to]);
				addd(col[e[i].to],col[e[i].from]);
			}
		}
		dfss(1,0);
		for(int i=2;i<=cnt;i+=2){
			if(col[e[i].from]!=col[e[i].to]){
				int Min=min(tot[col[e[i].from]],tot[col[e[i].to]]);
				if(Min%2==0&&(m-Min-1)%2==0)tmp=min(tmp,e[i].value);
			}
			else tmp=min(tmp,e[i].value);
		}
		cout<<sum-tmp;
	}
	return 0;
}