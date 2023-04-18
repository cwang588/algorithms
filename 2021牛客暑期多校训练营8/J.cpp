#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[1000006];
int cnt,Head[500005],n,s,t;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int depth[500005],len[500005],son[500005],fa[500005];
void dfs(int now,int pre){
	depth[now]=depth[pre]+1;
	fa[now]=pre;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		if(to==t||son[to])son[now]=to;
	}
}
void dfss(int now,int pre,int top){
	
}
int main(){
	cin>>n>>s>>t;
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(s,0);
	return 0;
}
