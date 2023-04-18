#include<bits/stdc++.h>
using namespace std;
const long long inf=1145141919810ll;
long long v[105],t[105];
long long dp[105][3605][15];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>v[i]>>t[i];
	int Min=1800-1305,Max=1800+1305;
	for(int i=0;i<=n;++i){
		for(int j=Min;j<=Max;++j){
			for(int k=0;k<=m;++k)dp[i][j][k]=-inf;
		}
	}
	dp[0][1800][0]=0;
	long long ans=0;
	for(int i=0;i<n;++i){
		for(int j=Min;j<=Max;++j){
			for(int k=0;k<=m;++k){
				if(dp[i][j][k]==-inf)continue;
				dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
				if(j-t[i+1]>=Min)dp[i+1][j-t[i+1]][k]=max(dp[i+1][j-t[i+1]][k],dp[i][j][k]+v[i+1]);
				if(j+t[i+1]<=Max)dp[i+1][j+t[i+1]][k]=max(dp[i+1][j+t[i+1]][k],dp[i][j][k]+v[i+1]);
				if(k==m)continue;
				if(j-t[i+1]*2>=Min)dp[i+1][j-t[i+1]*2][k+1]=max(dp[i+1][j-t[i+1]*2][k+1],dp[i][j][k]+v[i+1]);
				if(j+t[i+1]*2<=Max)dp[i+1][j+t[i+1]*2][k+1]=max(dp[i+1][j+t[i+1]*2][k+1],dp[i][j][k]+v[i+1]);
			}
		}
	}
	for(int k=0;k<=m;++k)ans=max(ans,dp[n][1800][k]);
	cout<<ans;
	return 0;
}