#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int db[7][7]={{3,9,27,81,243,729,2187},
{9,66,390,1800,6120,13680,15120},
{27,390,3198,13176,27000,13680,15120},
{81,1800,13176,24336,4320,0,0},
{243,6120,27000,4320,4320,0,0},
{729,13680,13680,0,0,0,0},
{2187,15120,15120,0,0,0,0}};
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
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		long long ans=quickpower(3,n*m,mod);
		if(n<=7&&m<=7)ans=(ans+mod-db[n-1][m-1])%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
