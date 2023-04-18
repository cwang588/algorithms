#include<bits/stdc++.h>
using namespace std;
int d[505],a[505];
long long dp[505][505];
const long long inf=1919810114514;
int main(){
	int n,l,m;
	cin>>n>>l>>m;
	for(int i=1;i<=n;++i)cin>>d[i];
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j)dp[i][j]=inf;
	}
	++n;
	d[n]=l;
	dp[1][0]=0;
	for(int i=2;i<=n;++i){
		dp[i][0]=dp[i-1][0]+1ll*a[i-1]*(d[i]-d[i-1]);
		for(int j=1;j<=m;++j){
			dp[i][j]=inf;
			for(int k=1;k<i;++k){
				if(i-k-1>j)continue;
				dp[i][j]=min(dp[i][j],dp[k][j-i+k+1]+1ll*a[k]*(d[i]-d[k]));
			}
		}
	}
	long long ans=inf;
	for(int i=0;i<=m;++i)ans=min(ans,dp[n][i]);
	cout<<ans<<"\n";
	return 0;
}