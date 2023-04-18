#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	freopen("perechi3.in","r",stdin);
	freopen("perechi3.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		long long ans=0;
		for(long long i=1;i*i<=n;++i)
			ans+=2*(n/i);
		long long tep=(long long)sqrt(n);
		printf("%lld\n",ans-tep*tep);
	}
	
	return 0;
}
