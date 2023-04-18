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
int degree[100005],dp[100005];
queue<int>q;
int main(){
	int n,m; 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		++degree[y];
	}
	for(int i=1;i<=n;++i){
		if(!degree[i]){
			q.push(i);
			dp[i]=1;
		}
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=Head[now];i;i=e[i].nxt){
			int to=e[i].to;
			dp[to]=max(dp[to],dp[now]+1);
			--degree[to];
			if(!degree[to])q.push(to);
		}
	}
	for(int i=1;i<=n;++i)printf("%d\n",dp[i]);
	return 0; 
}
