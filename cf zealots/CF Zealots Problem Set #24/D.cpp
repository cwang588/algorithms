#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[200005];
int Head[200005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
long long num[200005],a[200005];
long long sum[200005],ans;
void dfs(int now){
	sum[now]=a[now];
	if(!Head[now]){
		num[now]=1;
		ans=max(ans,1ll*a[now]);
		return;
	}
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		dfs(to);
		num[now]+=num[to];
		sum[now]+=sum[to];
	}
	if(sum[now])ans=max(ans,(sum[now]-1)/num[now]+1);
}
int main(){
	int n;
	cin>>n;
	for(int i=2;i<=n;++i){
		int x;
		cin>>x;
		add(x,i);
	}
	for(int i=1;i<=n;++i)cin>>a[i];
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}