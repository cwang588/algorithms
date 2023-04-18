#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long x[1005],y[1005];
long long calc(int i,int j)
{
	return (abs(x[i]-x[j])+abs(y[i]-y[j]))%mod;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld%lld",&x[i],&y[i]);
	long long ans=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			ans=(ans+(calc(i,j)%mod*(n-2))%mod)%mod;
	printf("%lld\n",ans);
	return 0;
}
