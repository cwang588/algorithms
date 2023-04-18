#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long dp[1005][1005][2];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<=n;++i)dp[1][i][0]=1;
		for(int i=1;i<=k;++i){
			for(int j=0;j<=n;++j){
				if(!j)dp[i][j][0]=dp[i][j][1]=1;
				else{
					dp[i][j][0]=dp[i][j-1][0]+dp[i-1][n-j][1];
					dp[i][j][0]%=mod;
					dp[i][j][1]=dp[i][j-1][1]+dp[i-1][n-j][0];
					dp[i][j][1]%=mod;
				}
			}
		}
		printf("%I64d\n",dp[k][n][0]);
	}
	return 0;
}
