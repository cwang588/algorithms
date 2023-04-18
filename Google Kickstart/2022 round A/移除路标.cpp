#include<bits/stdc++.h>
using namespace std;
int a[505],d[505];
long long dp[505][505];
int main(){
	int n,l,m;
	cin>>n>>l>>m;
	for(int i=1;i<=n;++i)cin>>d[i];
	for(int i=1;i<=n;++i)cin>>a[i];
	d[++n]=l;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j)dp[i][j]=1e18;
	}
	dp[1][0]=0;
	for(int i=2;i<=n;++i){
		for(int j=0;j<=m;++j){
			for(int k=0;k<=j;++k){
				if(i-k-1<=0)break;
				dp[i][j]=min(dp[i][j],dp[i-k-1][j-k]+1ll*a[i-k-1]*(d[i]-d[i-k-1]));
			}
		}
	}
	long long ans=1e18;
	for(int i=0;i<=m;++i)ans=min(ans,dp[n][i]);
	cout<<ans;
	return 0;
}