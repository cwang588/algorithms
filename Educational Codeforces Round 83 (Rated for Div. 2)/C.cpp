#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		long long k;
		scanf("%d%lld",&n,&k);
		long long Max=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%lld",&a[i]);
			Max=max(Max,a[i]);
		}
		long long now=1;
		while(now<Max)now*=k;
		bool ky=true;
		while(now)
		{
			bool usd=false;
			for(int i=1;i<=n;++i)
			{
				if(a[i]>=now)
				{
					if(usd)
					{
						ky=false;
						break;
					}
					else
					{
						a[i]-=now;
						usd=true;
					}
				}
			}
			if(!ky)break;
			now/=k;
		}
		if(!ky)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
