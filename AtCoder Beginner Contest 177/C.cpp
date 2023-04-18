#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long a[200005];
int main()
{
	int n;
	scanf("%d",&n);
	long long tot1=0,tot2=0;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),tot1+=a[i],tot2+=a[i]*a[i]%mod;
	tot1%=mod;
	tot2%=mod;
	long long ans=tot1*tot1%mod;
	ans=(ans-tot2)%mod+mod;
	printf("%lld\n",ans*500000004%mod);
	return 0;
}
