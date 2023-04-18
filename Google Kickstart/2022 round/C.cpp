#include<bits/stdc++.h>
using namespace std;
int a[200005];
struct edge{
	int from,to,nxt;
}e[400005];
int cnt,Head[200005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int dp[200005];
int dfs(int now){
	if(dp[now])return dp[now];
	int re=1;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(a[now]>a[to])re+=dfs(to);
	}
	dp[now]=re;
	return dp[now];
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		cnt=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],dp[i]=Head[i]=0;
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			if(!dp[i]){
				dp[i]=dfs(i);
				ans=max(ans,dp[i]);
			}
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	
	return 0;
}