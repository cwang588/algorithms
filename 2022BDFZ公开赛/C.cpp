#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long dp[5005][5005];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n<=5000){
		for(int i=2;i<=n;++i){
			dp[i][i-1]=dp[i-1][i-2]+a[i]*(i-1);
			for(int k=i-2;k>=1;--k){
				dp[i][k]=max(dp[i][k+1],dp[i-1][k-1]+a[i]*k);
			}
			dp[i][0]=max(dp[i][1],dp[i-1][0]);
		}
		cout<<dp[n][0]<<"\n";
	}
	else{
		long long tot=0,ans=0;
		for(int i=1;i<=n;++i)tot+=a[i];
		int now=0;
		tot-=a[1];
		for(int i=2;i<=n;++i){
			if(tot>=0){
				++now;
				ans+=a[i]*now;
			}
			else now=0;
			tot-=a[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}