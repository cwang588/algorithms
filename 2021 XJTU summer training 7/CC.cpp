#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[400005];
int Head[200005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int col[200005],top[200005];
long long num[200005],numrt[200005],n,sz[200005];
long long calc(long long x){
	return x*(x-1)/2;
}
long long ans;
void dfs(int now,int pre){
	sz[now]=1;
	int tmp=top[col[now]];
	top[col[now]]=now;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		num[now]=0;
		dfs(to,now);
		sz[now]+=sz[to];
		ans-=calc(sz[to]-num[now]);
	}
	if(tmp)num[tmp]+=sz[now];
	else numrt[col[now]]+=sz[now];
	top[col[now]]=tmp;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Case=0;
	while(cin>>n){
		cnt=0;
		memset(Head,0,sizeof(Head));
		memset(num,0,sizeof(num));
		memset(top,0,sizeof(top));
		memset(numrt,0,sizeof(numrt));
		for(int i=1;i<=n;++i)cin>>col[i];
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		ans=calc(n)*n;
		dfs(1,0);
		for(int i=1;i<=n;++i)ans-=calc(n-numrt[i]);
		cout<<"Case #"<<++Case<<": "<<ans<<"\n";
	}
	
	return 0;
}
