#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long jc[10000005],fjc[10000005],dp[10000005],sum[10000005];
long long quickpower(long long a,long long b,long long p)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)
			ans=(ans*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ans%p;
}
void init(){
	jc[0]=1;
	for(int i=1;i<=10000000;++i)jc[i]=jc[i-1]*i%mod;
	fjc[10000000]=quickpower(jc[10000000],mod-2,mod);
	for(int i=10000000;i>=1;--i)fjc[i-1]=fjc[i]*i%mod; 
}
int main(){
	init();
	int n,k;
	scanf("%d%d",&n,&k);
	dp[0]=sum[0]=1;
	for(int i=1;i<=n;++i){
		if(i-min(i,k)-1>=0)dp[i]=(sum[i-1]-sum[i-min(i,k)-1])*jc[i-1]%mod;
		else dp[i]=sum[i-1]*jc[i-1]%mod;
		sum[i]=(sum[i-1]+dp[i]*fjc[i]%mod)%mod;
	}
	printf("%lld\n",(dp[n]+mod)%mod);
	return 0;
}
