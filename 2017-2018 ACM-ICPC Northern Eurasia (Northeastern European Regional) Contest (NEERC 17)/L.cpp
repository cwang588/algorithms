#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[200005];
int Head[200005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
struct query{
	int x,y,lca,dis;
}q[100005];
int fa[100005][25],depth[100005];
void dfs(int now,int pre){
	depth[now]=depth[pre]+1;
	fa[now][0]=pre;
	for(int i=1;i<=20;++i)fa[now][i]=fa[fa[now][i-1]][i-1];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
	}
}
int lca(int x,int y){
	if(depth[x]<depth[y])swap(x,y);
	for(int i=20;i>=0;--i)if(depth[fa[x][i]]>=depth[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;--i){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
bool cmp(query a,query b){
	return a.dis>b.dis;
}
int col[100005];
void color(int id){
	int now=q[id].x;
	while(true){
		col[now]=id;
		if(now==q[id].lca)break;
		now=fa[now][0];
	}
	now=q[id].y;
	while(true){
		col[now]=id;
		if(now==q[id].lca)break;
		now=fa[now][0];
	}
}
int num[]={0,2,3,5,7,11,13,19260817};
unsigned long long value[100005][25],sum[100005][25],mi[25][100005];
void dfss(int now,int pre){
	for(int i=1;i<=7;++i)sum[now][i]=sum[pre][i]+value[now][i];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfss(to,now);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=m;++i)cin>>q[i].x>>q[i].y;
	dfs(1,0);
	for(int i=1;i<=m;++i){
		q[i].lca=lca(q[i].x,q[i].y);
		q[i].dis=depth[q[i].x]+depth[q[i].y]-2*depth[q[i].lca]+1;
	}
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=m;++i){
		if(!col[q[i].x]&&!col[q[i].y])color(i);
		else if(col[q[i].x]!=col[q[i].y])return !printf("No\n");
		else;
	}
	for(int i=1;i<=7;++i){
		mi[i][0]=1;
		for(int j=1;j<=m;++j)mi[i][j]=mi[i][j-1]*num[i];
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=7;++j){
			value[q[i].x][j]+=mi[j][i];
			value[q[i].y][j]-=mi[j][i];
		}
	}
	dfss(1,0);
	for(int i=1;i<=m;++i){
		for(int j=1;j<=7;++j){
			if(sum[q[i].x][j]+sum[q[i].y][j]-sum[q[i].lca][j]*2+value[q[i].lca][j])return !printf("No\n");
		}
		for(int j=1;j<=7;++j){
			value[q[i].x][j]-=mi[j][i];
			value[q[i].y][j]+=mi[j][i];
		}
	}
	cout<<"Yes\n";
	return 0;
}