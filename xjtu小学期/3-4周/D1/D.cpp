#include<bits/stdc++.h>
using namespace std;
map<int,long long>m1,m2;
int a[55];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int m=n/2;
	for(int i=0;i<(1<<m);++i)
	{
		int num=0,tot=0;
		for(int j=0;(1<<j)<=i;++j)
			if(i&(1<<j))
			{
				++num;
				tot+=a[j+1];
			}
		if(num%2)
			++m1[tot];
		else
			++m2[tot];
	}
	long long ans=0;
	int r=n-m;
	for(int i=0;i<(1<<r);++i)
	{
		int num=0,tot=0;
		for(int j=0;(1<<j)<=i;++j)
			if(i&(1<<j))
			{
				++num;
				tot+=a[j+1+m];
			}
		if(num%2)
			ans+=m1[-tot];
		else
			ans+=m2[-tot];		
	}
	printf("%lld",ans-1);
	return 0;
}
