#include<cstdio>
using namespace std;
const long long mod=1e9+7;
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
int main()
{
	freopen("azerah.in","r",stdin);
	freopen("azerah.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,t;
		long long x=0,y=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&t);
			if(t%2)
				++x;
			else
				++y;
		}
		if(!x)
		{
			printf("%lld\n",quickpower(2,y,mod)-1);
			continue;
		}
		long long ans=quickpower(2,x+y-1,mod)-1;
		while(ans<0)
			ans+=mod;
		printf("%lld\n",ans);
	}
	
	return 0;
}
