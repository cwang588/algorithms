#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[2000005];
int Head[20005],cnt,dfn[20005],low[20005],dfncnt;
bool usd[20005],usdd[2000005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void tarjan(int now,int root){
	dfn[now]=low[now]=++dfncnt;
	int sz=0;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
	//	if(to==root)continue;
		if(!dfn[to]){
			tarjan(to,root);
			low[now]=min(low[now],low[to]);
			if(low[to]>=dfn[now]&&now!=root)usd[now]=true;
			if(low[to]>dfn[now])usdd[i]=true;
			++sz;
		}
		else low[now]=min(low[now],dfn[to]);
	}
	if(now==root&&sz>1)usd[now]=true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i,i);
		int num1=0,num2=0;
		for(int i=1;i<=n;++i)if(usd[i])++num1;
		for(int i=1;i<=cnt;++i)if(usdd[i])++num2;
		printf("%d %d\n",num1,num2/2);
	}
	return 0;
}
