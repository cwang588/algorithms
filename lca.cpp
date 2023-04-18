#include<bits/stdc++.h>
using namespace std;
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
int fa[500005][25],depth[500005];
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
	for(int i=20;i>=0;--i){
		if(depth[fa[x][i]]>=depth[y])x=fa[x][i];
	}
	if(x==y)return x;
	for(int i=20;i>=0;--i){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int main(){
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(s,0);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y)); 
	}
	return 0;
}
