#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[200005];
int cnt,Head[100005];
long long a[100005],tot;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
long long ans=0;
void dfs(int now,int pre){
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		int tmp=abs(a[to]-tot);
		ans+=tmp;
		a[now]+=a[to]-tot;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],tot+=a[i];
	tot/=n;
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
