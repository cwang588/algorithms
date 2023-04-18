#include<cstdio>
#include<algorithm>
using namespace std;
long long a[200005];
int main()
{
	long long n,k,tot=0;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		tot=max(a[i],tot);
	}
	long long l=0,r=tot,ans;
	while(l<r-1)
	{
		long long mid=(l+r)>>1;
		long long sum=0;
		if(!mid)
		{
			r=mid-1;
			continue;
		}
		for(int i=1;i<=n;++i)
			sum+=a[i]/mid;
		if(sum>=k)
			l=mid;
		else
			r=mid;	
	}
	long long num=0;
	if(ans)
	{
		for(int i=1;i<=n;++i)
			num+=a[i]/ans;	
		if(num<k)
			ans--;
	}
	if(ans<0)
		ans=0;
	printf("%lld",ans);
	return 0;
}
