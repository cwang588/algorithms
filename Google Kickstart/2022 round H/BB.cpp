#include<bits/stdc++.h>
using namespace std;
const int n=1000;
int dp[n+5][n+5],ans[n+1005];
int main(){
	for(int i=1;i<=n;++i)for(int j=0;j<=n;++j)dp[i][j]=100000;
	for(int i=0;i<=n;++i)ans[i]=100000;
	for(int i=0;i<n;++i){
		for(int j=0;j<=i;++j){
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
			if(j&&i+j<=n)dp[i+j][j]=min(dp[i+j][j],dp[i][j]+2);
			if(i!=j)dp[i][i]=min(dp[i][i],dp[i][j]+4);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i;++j)ans[i]=min(ans[i],dp[i][j]);
	}
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int m;
		cin>>m;
		cout<<"Case #"<<Case<<": "<<ans[m]<<"\n";
	}
	
	return 0;
}