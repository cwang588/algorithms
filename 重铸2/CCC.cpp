#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[2000005];
int cnt,Head[1000005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool usd[1000005];
void dfs(int now,int fa){
	usd[now]=true;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==fa)continue;
		dfs(to,now);
	}
}
int main(){
	freopen("007","r",stdin);
	freopen("out.txt","w",stdout);
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
	for(int i=1;i<=n;++i)if(!usd[i])dfs(i,0);
	return 0;
}
