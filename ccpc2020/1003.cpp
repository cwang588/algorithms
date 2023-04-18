#include<bits/stdc++.h>
using namespace std;
const long long inf=11451411451411451ll;
long long a[1000005],b[1000005];
long long work(long long x)
{
	if(x>=0)return x;
	return -x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		long long k,tot=0;
		scanf("%d%d%lld",&n,&m,&k);
		for(int i=1;i<=m;++i)
		{
			scanf("%lld",&a[i]);
			b[i]=work(a[i]-k);
			tot+=b[i]*2;
		}
		long long ans=inf;
		for(int i=1;i<=m;++i)ans=min(ans,k+tot-b[i]+a[i]-2);
		printf("%lld\n",ans);
	}
	return 0;
}
