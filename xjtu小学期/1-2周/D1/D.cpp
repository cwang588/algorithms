#include<bits/stdc++.h>
using namespace std;
map<int,long long>m;
int a[50];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int l=n/2,r=n-l;
	for(int i=0;i<(1<<r);++i)
	{
		int tot=0;
		for(int j=0;j<r;++j)
			if((i>>j)&1)
				tot+=a[n-j];
		++m[tot];
	}
	long long ans=0;
	for(int i=0;i<(1<<l);++i)
	{
		int tot=0;
		for(int j=0;j<l;++j)
			if((i>>j)&1)
				tot+=a[l-j];
		ans+=m[-tot];
	}
	printf("%lld",ans-1);
	return 0;
}
