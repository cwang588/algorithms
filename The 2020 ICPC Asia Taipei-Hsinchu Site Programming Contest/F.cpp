#include<bits/stdc++.h>
using namespace std;
const int inf=19260817;
struct edge{
	int from,to,nxt;
}e[500005];
int Head[200005],cnt,dp[200005][2],n,m,f[100005][2][2];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs(int now,int pre){
	int cnt1=0,cnt2=0;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre||to<=n)continue;
		dfs(to,now);
		cnt1+=min(dp[to][0],dp[to][1]);
		cnt2+=dp[to][1];
	}
	dp[now][0]=cnt2;
	dp[now][1]=cnt1+1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n+m;++i){
		int x,y;
		cin>>x>>y;
		++x,++y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;++i)dfs(i,0);
	f[1][0][0]=dp[1][0];
	f[1][1][1]=dp[1][1];
	f[1][0][1]=f[1][1][0]=inf;
	for(int i=2;i<=n;++i){
		for(int j=0;j<=1;++j){
			f[i][0][j]=f[i-1][1][j]+dp[i][0];
			f[i][1][j]=min(f[i-1][0][j],f[i-1][1][j])+dp[i][1];
		}
	}
	int ans=inf;
	for(int i=0;i<=1;++i){
		for(int j=0;j<=1;++j){
			if(i==0&&j==0)continue;
			ans=min(ans,f[n][i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
