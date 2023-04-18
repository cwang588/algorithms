#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long ans=0,sum=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lld%lld",&a[i],&b[i]),sum+=b[i];
		for(int i=1;i<=n;++i)ans+=min(a[i],sum-b[i]);
		printf("%lld\n",min(ans,sum));
	}
	return 0;
}
