#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long dp[1000005],sum[1000085];
int mi[35];
int main(){
	int n;
	cin>>n;
	mi[0]=1;
	for(int i=1;i<=30;++i)mi[i]=mi[i-1]<<1;
	for(int i=1;i<=n;++i){
		dp[i]=sum[i-1]+1;
		for(int j=0;j<=30;++j){
			if((i&mi[j])>0&&mi[j+1]<=i)dp[i]=(dp[i]-sum[mi[j+1]-1]+sum[mi[j]-1])%mod;
		}
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	cout<<(sum[n]+mod)%mod;
	return 0;
}
