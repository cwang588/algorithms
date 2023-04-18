#include<bits/stdc++.h>
using namespace std;
int a[5005];
int dp[5005][10005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=0;i<=n;++i){
			for(int j=0;j<=8192;++j)dp[i][j]=10000;
		}
		dp[0][0]=0;
		for(int i=1;i<=n;++i){
			dp[i][0]=dp[i-1][0]+1;
			dp[i][a[i]]=dp[i-1][0];
			for(int j=1;j<=8192;++j){
				dp[i][j^a[i]]=min(dp[i][j^a[i]],dp[i-1][j]+1);
			}
		}
		cout<<dp[n][0]<<"\n";
	}
	
	
	return 0;
}