#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[4000005];
int cnt,Head[200005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
char col[200005];
int num[200005],fa[200005];
void dfs(int now,int pre){
	num[now]=1;
	fa[now]=pre;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		num[now]+=num[to];
		if(col[now]==col[to])--num[now];
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>col[i];
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	long long ans=0;
	for(int i=2;i<=n;++i){
		if(col[i]==col[fa[i]])ans+=abs(num[1]-2*num[i]+1);
		else ans+=abs(num[1]-2*num[i]);
	}
	cout<<ans<<"\n";
	return 0;
}