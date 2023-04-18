#include<cstdio>
using namespace std;
long long a[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	long long ans=0,tot=0;
	for(int i=1;i<=n+1;++i)
	{
		if(!a[i])
		{
			ans+=tot/2;
			tot=0;
		}
		tot+=a[i];
	}
	printf("%lld",ans);
	return 0;
}
