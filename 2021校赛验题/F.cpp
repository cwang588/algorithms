#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long dp[1005][1005][2];
int main(){
	dp[1][0][0]=1;
	for(int i=2;i<=1000;++i){
		for(int j=0;j<i;++j){
			dp[i][j][0]=dp[i-1][j+1][0]*(j+1)%mod+dp[i-1][j][0]*(i-j-2)%mod+dp[i-1][j][1]*(i-j-1)%mod+dp[i-1][j+1][1]*j%mod;
			dp[i][j][1]=dp[i-1][j-1][0]*2%mod+dp[i-1][j][1]+dp[i-1][j-1][1];
			dp[i][j][0]%=mod;
			dp[i][j][1]%=mod;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		printf("%lld\n",(dp[n][k][0]+dp[n][k][1])%mod);
	}
	return 0;
}
