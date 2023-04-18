#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
	int from,to,nxt,value;
}e[400005];
int Head[200005],cnt;
void add(int x,int y,int z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int sz[200005];
long long sum[200005];
int ans;
bool dfs(int now){
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(dfs(to)){
			sz[now]+=sz[to];
			sum[now]+=1ll*e[i].value*sz[to]+sum[to];
		}
	}
	if(sz[now]==0){
		sz[now]=1;
		return true;
	}
	if(sum[now]>m){
		++ans;
		return false;
	}
	return true;
}
int main(){
	cin>>n>>m;
	for(int i=2;i<=n;++i){
		int x,y;
		cin>>x>>y;
		add(x,i,y);
	}
	dfs(1);
	cout<<ans;
	return 0;
}