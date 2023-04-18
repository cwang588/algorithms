#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[200005];
int cnt,Head[100005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int rd[10005],dp[10005],nxt[10005];
void dfs(int now){
	dp[now]=1;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		dfs(to);
		if(dp[to]+1>dp[now]){
			dp[now]=dp[to]+1;
			nxt[now]=to;
		}
		else if(dp[to]+1==dp[now]){
			if(to<nxt[now])nxt[now]=to;
		}
		else;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		nxt[i]=-1;
		int num;
		cin>>num;
		while(num--){
			int tmp;
			cin>>tmp;
			add(i,tmp);
			++rd[tmp];
		}
	}
	int s;
	for(int i=0;i<n;++i){
		if(!rd[i]){
			s=i;
			break;
		}
	}
	dfs(s);
	printf("%d\n",dp[s]);
	int now=s;
	while(nxt[now]!=-1){
		printf("%d ",now);
		now=nxt[now];
	}
	printf("%d",now);
	return 0;
}
