#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int dp[35][2][2][2];
int a[35],b[36];
int dfs(int now,int sx,int sy,int lead){
	if(now==0)return 1;
	if(dp[now][sx][sy][lead]!=-1)return dp[now][sx][sy][lead];
	int upx=sx?a[now]:1,upy=sy?b[now]:1,tmp=0;
	for(int i=0;i<=upx;++i){
		for(int j=0;j<=upy;++j){
			if(i&j)continue;
			int cnt=1;
			if(lead&&(i||j))cnt=now;
			tmp+=1ll*dfs(now-1,sx&&i==upx,sy&&j==upy,lead&&i==0&&j==0)*cnt%mod;
			tmp%=mod;
		}
	}
	return dp[now][sx][sy][lead]=tmp;
}
int calc(int x,int y){
	memset(dp,-1,sizeof(dp));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int pos1=0,pos2=0;
	while(x){
		a[++pos1]=x&1;
		x>>=1;
	}
	while(y){
		b[++pos2]=y&1;
		y>>=1;
	}
	return dfs(max(pos1,pos2),1,1,1);
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		cout<<(calc(x,y)-1+mod)%mod<<"\n";
	}
	return 0;
}