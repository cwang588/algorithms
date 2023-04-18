#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long dp[2000005];
int main(){
	int n;
	scanf("%d",&n);
	dp[0]=1;
	dp[6]=-1;
	for(int i=1;i<=n;++i){
		if(i>=2)dp[i]=(dp[i]+dp[i-2])%mod;
		if(i>=3)dp[i]=(dp[i]+dp[i-3])%mod;
		if(i>=4)dp[i]=(dp[i]+dp[i-4])%mod;
		if(i>=5)dp[i]=(dp[i]+dp[i-5]*3)%mod;
		if(i>=6)dp[i]=(dp[i]+dp[i-6]*3)%mod;
		if(i>=7)dp[i]=(dp[i]+dp[i-7])%mod;
	}
	printf("%lld\n",dp[n]);
	return 0;
}
