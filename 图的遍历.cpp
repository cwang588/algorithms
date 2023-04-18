#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[200005];
int Head[100005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int value[100005];
void dfs(int now,int ans){
	value[now]=ans;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(value[to])continue;
		dfs(to,ans);
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		add(y,x);
	}
	for(int i=n;i>=1;--i){
		if(!value[i]){
			dfs(i,i);
		}
	}
	for(int i=1;i<=n;++i)printf("%d ",value[i]);
	printf("\n");
	return 0;
}
